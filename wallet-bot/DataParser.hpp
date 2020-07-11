#pragma once
#include <algorithm>
#include <nlohmann/json.hpp>
#include "Config.hpp"
#include "Exception.hpp"
#include "HttpClient.hpp"
#include "TelegramBotAPI.hpp"

using json = nlohmann::json;

namespace tlg_bot
{
    class DataParser
    {
    public:
        DataParser(PConfig &upconfig);
        void process_json_data(const std::string &data);

    private:
        void is_valid_json(const std::string &data);
        std::string create_message(std::string &action_type, std::string &value, const std::string &user);
        void check_value(std::string &value);
        void format_big_value(std::string &value);

        PHttp m_uphttp;
        PTlgBotAPI m_uptlgapi;
        PConfig &m_upconfig;
    };
    using PDataParser = std::unique_ptr<DataParser>;
} // namespace tlg_bot
