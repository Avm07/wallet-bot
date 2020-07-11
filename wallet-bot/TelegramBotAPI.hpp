#pragma once
#include "Config.hpp"

namespace tlg_bot
{
    class TelegramBotAPI
    {
    public:
        TelegramBotAPI(PConfig &cfg);

        std::string get_me();
        std::string get_updates();
        std::string send_message(const std::string &text);

    private:
        PConfig &m_upcfg;
    };
    using PTlgBotAPI = std::unique_ptr<TelegramBotAPI>;
} // namespace tlg_bot