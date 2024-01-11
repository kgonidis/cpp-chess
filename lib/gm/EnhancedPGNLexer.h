
// Generated from EnhancedPGNLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  EnhancedPGNLexer : public antlr4::Lexer {
public:
  enum {
    TAG_START = 1, STRING = 2, MOVE_TEXT_START = 3, MOVE_TEXT_START_WITH_COMMENT = 4, 
    NEW_LINE = 5, TAG_END = 6, TAG_VALUE = 7, TAG_KEY = 8, TAG_SPACE = 9, 
    EOL_COMMENT_START = 10, MOVE_NUM = 11, BLOCK_COMMENT_START = 12, WS = 13, 
    PIECE = 14, LOCATION = 15, PROMOTION = 16, RANK = 17, FILE = 18, SHORT_CASTLE = 19, 
    LONG_CASTLE = 20, CAPTURE_MARKER = 21, ALTERNATE_LINE_START = 22, ALTERNATE_LINE_END = 23, 
    BLUNDER = 24, MISTAKE = 25, DUBIOUS_MOVE = 26, INTERESTING_MOVE = 27, 
    GOOD_MOVE = 28, BRILLIANT_MOVE = 29, CHECK = 30, CHECKMATE = 31, WHITE_WINS = 32, 
    BLACK_WINS = 33, DRAW = 34, UNKOWN_ENDING = 35, NAG = 36, EOL_COMMENT_TEXT = 37, 
    EOL_COMMENT_END = 38, COMMAND_START = 39, BLOCK_COMMENT_END = 40, BLOCK_COMMENT_TEXT = 41, 
    COMMAND_ID = 42, COMMAND_END = 43, COMMA = 44, PARAM_TEXT = 45
  };

  enum {
    TAG_PAIRS = 1, MOVE_TEXT = 2, EOL_COMMENT = 3, BLOCK_COMMENT = 4, COMMAND = 5, 
    COMMAND_PARAMS = 6
  };

  explicit EnhancedPGNLexer(antlr4::CharStream *input);

  ~EnhancedPGNLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

