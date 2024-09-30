
add_executable(chessengine_test
    main.cpp
)

target_include_directories(chessengine_test PUBLIC
    ../ui/inc
    ../lib/inc
)

target_link_libraries(chessengine_test
    mui
    chessengine
)

add_executable(gametree_test
    gametree_test.cpp
)

target_include_directories(gametree_test PUBLIC
    ../ui/inc
    ../lib/inc
)

target_link_libraries(gametree_test
    mui
    chessengine
)

add_executable(chessengine_c_test
    test.c
)

target_include_directories(chessengine_c_test PUBLIC
    ../lib/inc
)

target_link_libraries(chessengine_c_test
    chessengine
)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})