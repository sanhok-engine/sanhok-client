cmake_minimum_required(VERSION 3.28)
project(compile-protocol-schemas
    VERSION 0.1
    LANGUAGES CXX
)

add_subdirectory(flatbuffers)

file(GLOB schemas RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} game-protocol-schemas/*.fbs)
    add_custom_target(game-protocol-schemas
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND
    flatc
    --cpp
    --cpp-std c++17
    --filename-suffix "\"\""
    --filename-ext hpp
    -o ../SanhokNetworking/Public/sanhok/protocol
    ${schemas}
    DEPENDS flatc
)