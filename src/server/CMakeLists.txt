file(GLOB SERVER_SOURCES "*.cpp")

add_executable(server ${SERVER_SOURCES})

target_link_libraries(server
    Poco::Foundation
    Poco::Util
    Poco::Net
    hiredis_lib
    nlohmann_json::nlohmann_json
)