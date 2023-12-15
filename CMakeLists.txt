cmake_minimum_required(VERSION 3.15)

project(chessengine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-private-field -Wno-unused-but-set-variable -Wno-unused-lambda-capture -Wno-unused-local-typedefs -Wno-unused-value -Wno-unused-const-variable")

add_library(chessengine STATIC
    src/engine.cpp
    src/types.cpp
    src/game.cpp
    src/constants.cpp
    src/movement.cpp
    src/keys.cpp
)

target_include_directories(chessengine PUBLIC
    include
)

add_executable(chessengine_test
    test/main.cpp
)

target_include_directories(chessengine_test PUBLIC
    include
)

target_link_libraries(chessengine_test
    chessengine
)
