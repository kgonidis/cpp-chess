
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc ${CMAKE_CURRENT_SOURCE_DIR}/ui/inc)

add_executable(chessengine_test
    main.cpp
)
target_include_directories(chessengine_test PUBLIC
    ${INCLUDE_DIRS}
)
target_link_libraries(chessengine_test
    mui
    chessengine
)

add_executable(gametree_test
    gametree_test.cpp
)
target_include_directories(gametree_test PUBLIC
    ${INCLUDE_DIRS}
)
target_link_libraries(gametree_test
    mui
    chessengine
)

add_executable(chessengine_c_test
    test.c
)
target_include_directories(chessengine_c_test PUBLIC
    ${INCLUDE_DIRS}
)
target_link_libraries(chessengine_c_test
    chessengine
)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})