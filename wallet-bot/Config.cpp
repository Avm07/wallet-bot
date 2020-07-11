#include "Config.hpp"

using namespace tlg_bot;

Config::Config()
    : m_host(get_env_value("TLG_API_HOST", "api.telegram.org")),
      m_api_token(get_env_value("TLG_BOT_API_TOKEN", "")),
      m_chat_id(get_env_value("TLG_CHAT_ID", "")),
      m_db_address(get_env_value("MONGO_DB_HOST", "localhost")),
      m_db_port(get_env_value("MONGO_DB_PORT", "27017")),
      m_db_name(get_env_value("MONGO_DB_NAME", "mydb")),
      m_db_user_name(get_env_value("MONGO_DB_USR", "admin")),
      m_db_user_pwd(get_env_value("MONGO_DB_PWD", "admin"))
{
}

std::string Config::get_host() const
{
    return m_host;
}

std::string Config::get_api_token() const
{
    return m_api_token;
}

std::string Config::get_chat_id() const
{
    return m_chat_id;
}

std::string Config::get_db_address() const
{
    return m_db_address;
}

std::string Config::get_db_port() const
{
    return m_db_port;
}

std::string Config::get_db_name() const
{
    return m_db_name;
}

std::string Config::get_db_user_name() const
{
    return m_db_user_name;
}

std::string Config::get_db_user_pwd() const
{
    return m_db_user_pwd;
}

std::string Config::get_env_value(const std::string &env_name, const std::string &default_value) const
{
    auto param = std::getenv(env_name.c_str());
    return (param != nullptr) ? param : default_value;
}
