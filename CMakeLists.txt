cmake_minimum_required(VERSION 3.15)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_UI "Build UI" OFF)
set(CHESSENGINE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

project(chessengine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-private-field -Wno-unused-but-set-variable -Wno-unused-lambda-capture -Wno-unused-local-typedefs -Wno-unused-value -Wno-unused-const-variable -Wno-sign-compare")

if(BUILD_UI)
    message(STATUS "BUILD UI = ON")
    add_subdirectory(ui)
else()
    message(STATUS "BUILD UI = OFF")
endif()

add_subdirectory(lib)

if(BUILD_TESTS)
    message(STATUS "BUILD TESTS = ON")
    add_subdirectory(test)
else()
    message(STATUS "BUILD TESTS = OFF")
endif()