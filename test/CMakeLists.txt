

add_executable(chessengine_test
    chessengine_test.cpp
)
target_include_directories(chessengine_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc
)
target_link_libraries(chessengine_test
    chessengine
)

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