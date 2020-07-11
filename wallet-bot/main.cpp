#include <iostream>
#include "HttpClient.hpp"
#include "MongoDbReader.hpp"
#include "Config.hpp"

using namespace tlg_bot;

int main()
{
    try
    {
        MongoDbWrapper mongo;
        mongo.watch_change_stream();
    }
    catch (std::exception const &e)
    {
        spdlog::error("Error : {}",e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}