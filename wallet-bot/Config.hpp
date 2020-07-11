#pragma once
#include <string>
#include <memory>

namespace tlg_bot
{
    class Config
    {
    public:
        Config();

        std::string get_host() const;
        std::string get_api_token() const;
        std::string get_chat_id() const;

        std::string get_db_address() const;
        std::string get_db_port() const;
        std::string get_db_name() const;
        std::string get_db_user_name() const;
        std::string get_db_user_pwd() const;

    private:
        std::string get_env_value(const std::string &env_name, const std::string &default_value) const;

        std::string m_host;
        std::string m_api_token;
        std::string m_chat_id;

        std::string m_db_address;
        std::string m_db_port;
        std::string m_db_name;
        std::string m_db_user_name;
        std::string m_db_user_pwd;
    };
    using PConfig = std::unique_ptr<Config>;
} // namespace tlg_bot
