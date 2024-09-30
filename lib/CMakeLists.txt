set(HOMEBREW_DIR /opt/homebrew)

add_library(chessengine SHARED
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
    ${HOMEBREW_DIR}/include/antlr4-runtime
)

target_link_libraries(chessengine PUBLIC
    ${HOMEBREW_DIR}/lib/libantlr4-runtime.a
)
