#include "DataParser.hpp"

using namespace tlg_bot;

DataParser::DataParser(PConfig &upconfig) : m_upconfig(upconfig)
{
    m_uphttp = std::make_unique<HttpClient>();
    m_uptlgapi = std::make_unique<TelegramBotAPI>(TelegramBotAPI(upconfig));
}

void DataParser::is_valid_json(const std::string &data)
{
    if (!json::accept(data))
    {
        throw Exception ("Invalid json");
    }
}

void DataParser::process_json_data(const std::string &data)
{
    try
    {
        is_valid_json(data);
        json j_data = json::parse(data);
        auto operationType = j_data["operationType"].get<std::string>();

        if (operationType == "insert")
        {
            auto action_type = j_data["fullDocument"]["action_type"].get<std::string>();
            if (action_type == "deposit" || action_type == "withdraw")
            {
                auto value = j_data["fullDocument"]["value"].get<std::string>();
                auto user = j_data["fullDocument"]["to_user"].get<std::string>();
                auto msg = create_message(action_type, value, user);
                m_uphttp->send_request_https(m_upconfig->get_host(), http::verb::post, m_uptlgapi->send_message(msg));
            }
        }
    }
    catch(Exception &e)
    {
        spdlog::error("Error: {}", e.what());
    }
    catch (...)
    {
        spdlog::error("Unxepected exception");
    }
}

std::string DataParser::create_message(std::string &action_type, std::string &value, const std::string &user)
{
    check_value(value);
    std::transform(action_type.begin(), action_type.begin() + 1, action_type.begin(), ::toupper);
    std::string text = action_type + ": <b>" + value + " USDT</b>" + "%0AUser: " + user + "&parse_mode=HTML";
    return text;
}

void DataParser::check_value(std::string &value)
{
    value.erase(value.end() - 8, value.end());
    switch(value.size())
    {
        case 1:
            value.insert(0,"00");
            break;
        case 2:
            value.insert(0,"0");
            break;
        default:
            format_big_value(value);
            break;
    }
    value.insert(value.end() - 2, 1, '.');
}

void DataParser::format_big_value(std::string &value)
{
    std::string str = value.substr(0,value.size()-2);
    int size = str.length() / 3;
    if(size > 0)
    {
        for (size_t i = 3*size; i >= 3; i-=3)
        {
            str.insert(str.length()-i,"%20");
        }
        value = str + value.substr(value.length()-2,value.length());
    }
}

