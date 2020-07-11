cmake_minimum_required(VERSION 3.14)

project(wallet-bot VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)

set(PLATFORM_SPECIFIC_LIBS pthread)

#MacOSX installing openssl via brew
if (${APPLE})
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1/")
    set(OPENSSL_INCLUDE_DIRS "/usr/local/opt/openssl@1.1/include")
endif ()

find_package(Boost 1.70 REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)

file(GLOB SOURCE
"./wallet-bot/*.cpp"
)

add_executable(
${PROJECT_NAME}
${SOURCE}
)

include_directories(
wallet-bot
${LIBMONGOCXX_INCLUDE_DIRS}
${LIBBSONCXX_INCLUDE_DIRS}
${Boost_INCLUDE_DIRS}
${OPENSSL_INCLUDE_DIRS}
)

target_link_libraries(
${PROJECT_NAME}
PRIVATE nlohmann_json::nlohmann_json
PRIVATE spdlog::spdlog_header_only
PRIVATE ${Boost_LIBRARIES} ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES}
PRIVATE ${OPENSSL_LIBRARIES}
pthread
)
