cmake_minimum_required(VERSION 3.15)

project(chessengine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-private-field -Wno-unused-but-set-variable -Wno-unused-lambda-capture -Wno-unused-local-typedefs -Wno-unused-value -Wno-unused-const-variable -Wno-sign-compare")

set(INCLUDE_UI CACHE BOOL "INCLUDE_UI")

add_definitions(-DINCLUDE_UI)

add_subdirectory(ui)

add_subdirectory(lib)

add_subdirectory(test)