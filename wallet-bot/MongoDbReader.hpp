#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include "spdlog/spdlog.h"
#include "Config.hpp"
#include "DataParser.hpp"

namespace tlg_bot
{
    class MongoDbWrapper
    {
    public:
        MongoDbWrapper();

        void watch_change_stream();

    private:
        std::string create_auth_uri(const std::string &address, const std::string &port,
                                    const std::string &user_name, const std::string &user_pwd);

        mongocxx::instance m_instance{};
        mongocxx::client m_client;
        mongocxx::database m_db;

        PConfig m_upcfg;
        PDataParser m_upparser;
    };
    using PMongo = std::unique_ptr<MongoDbWrapper>;
} // namespace tlg_bot
