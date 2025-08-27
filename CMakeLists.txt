cmake_minimum_required(VERSION 3.10)

project(REDIS_LOG_PROCESSING VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# POCO Import
find_package(Poco REQUIRED COMPONENTS Foundation Util Net)

# Redis Import
add_library(hiredis_lib INTERFACE)
target_include_directories(hiredis_lib INTERFACE /opt/homebrew/include)
target_link_directories(hiredis_lib INTERFACE /opt/homebrew/lib)
target_link_libraries(hiredis_lib INTERFACE hiredis)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src/server)
#add_subdirectory(src/client)