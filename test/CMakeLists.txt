include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(chessengine_test
    chessengine_test.cpp
)
target_include_directories(chessengine_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc
)
target_link_libraries(chessengine_test
    chessengine
    GTest::gtest_main
)
gtest_discover_tests(chessengine_test)


add_executable(chessengine_c_test
    chessengine_test.c
)
target_include_directories(chessengine_c_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc
)
target_link_libraries(chessengine_c_test
    chessengine
)

if(BUILD_UI)
    add_executable(ui_test
        ui_test.cpp
    )
    target_include_directories(ui_test PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc
        ${CHESSENGINE_ROOT_DIR}/ui/inc
    )
    target_link_libraries(ui_test
        mui
        chessengine
    )
endif()

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})