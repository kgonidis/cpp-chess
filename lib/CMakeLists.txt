add_subdirectory(gm)

add_library(chessengine STATIC 
    src/types.cpp
    src/game.cpp
    src/constants.c
    src/attacks.cpp
    src/movetree.cpp
    src/gametree.cpp
    gm/EnhancedPGNParser.cpp
    gm/EnhancedPGNLexer.cpp
)

target_include_directories(chessengine PUBLIC
    inc
    gm
    ${PROJECT_SOURCE_DIR}/vendor/antlr4/runtime/Cpp/runtime/src
)

target_link_libraries(chessengine PUBLIC
    antlr4_static
)
