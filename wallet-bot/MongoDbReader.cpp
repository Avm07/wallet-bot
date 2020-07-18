#include "MongoDbReader.hpp"

using namespace tlg_bot;

MongoDbWrapper::MongoDbWrapper()
{
    m_upcfg = std::make_unique<Config>(Config());
    m_upparser = std::make_unique<DataParser>(DataParser(m_upcfg));
    m_client = mongocxx::uri(create_auth_uri(m_upcfg->get_db_address(), m_upcfg->get_db_port(), m_upcfg->get_db_user_name(), m_upcfg->get_db_user_pwd()));
    m_db = m_client[m_upcfg->get_db_name()];
    spdlog::info("wallet-bot launched...");
}

void MongoDbWrapper::watch_change_stream()
{
    auto collection = m_db[m_upcfg->get_db_col_name()];

    mongocxx::change_stream stream = collection.watch();

    for (;;)
    {
        for (const auto &event : stream)
        {
            m_upparser->process_json_data(bsoncxx::to_json(event));
        }
    }
}

std::string MongoDbWrapper::create_auth_uri(const std::string &address, const std::string &port, const std::string &user_name, const std::string &user_pwd)
{
    std::string uri = "mongodb://" + user_name + ":" + user_pwd + "@" + address + ":" + port + "/admin";
    return uri;
}
