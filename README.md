[![GitHub](https://img.shields.io/github/license/Avm07/wallet-bot)](https://github.com/Avm07/wallet-bot/LICENCE.md)
[![CircleCI](https://circleci.com/gh/Avm07/wallet-bot.svg?style=svg)](https://circleci.com/gh/Avm07/wallet-bot)
# wallet-bot

Wallet-bot is a telegram bot which inform in channel about incoming documents from MongoDB using change stream.

# Dependencies

* Boost 1.70
* mongo-c-driver	
* mongo-cxx-driver
* spdlog
* nlohman/json
* openssl

# Compiling

```
mkdir build
cd build
cmake ..
# use "make -j N" for N CPU cores for faster compiling (may require more RAM)
make
```

# Environment variables

* TLG_API_HOST
* TLG_BOT_API_TOKEN 
* TLG_CHAT_ID
* MONGO_DB_HOST
* MONGO_DB_PORT
* MONGO_DB_NAME
* MONGO_DB_USR
* MONGO_DB_PWD

# Running

```
./wallet-bot
```