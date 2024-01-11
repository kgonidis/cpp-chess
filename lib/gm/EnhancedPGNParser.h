
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  EnhancedPGNParser : public antlr4::Parser {
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
    RuleParse = 0, RulePgn_database = 1, RulePgn = 2, RuleTag_pairs = 3, 
    RuleTag_pair = 4, RuleTag_key = 5, RuleTag_value = 6, RuleMove_text = 7, 
    RuleGame_termination = 8, RuleWhite_wins = 9, RuleBlack_wins = 10, RuleDraw = 11, 
    RuleUnknown_ending = 12, RuleMove_text_item = 13, RuleTurn_item = 14, 
    RuleNag = 15, RuleComment = 16, RuleEol_comment = 17, RuleEol_comment_body = 18, 
    RuleTurn = 19, RuleAlternate_line = 20, RuleMove_num = 21, RuleSan = 22, 
    RuleCheck_like = 23, RuleCheck = 24, RuleDouble_check = 25, RuleCheckmate = 26, 
    RuleMove_analysis = 27, RuleBlunder = 28, RuleMistake = 29, RuleDubious_move = 30, 
    RuleInteresting_move = 31, RuleGood_move = 32, RuleBrilliant_move = 33, 
    RuleCapture = 34, RulePawn_capture = 35, RulePiece_capture = 36, RulePawn_move = 37, 
    RulePromotion = 38, RulePiece = 39, RulePiece_move = 40, RuleCastle = 41, 
    RuleBlock_comment = 42, RuleBlock_comment_body = 43, RuleBlock_comment_text = 44, 
    RuleCommand = 45, RuleCommand_id = 46, RuleCommand_params = 47
  };

  explicit EnhancedPGNParser(antlr4::TokenStream *input);

  EnhancedPGNParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~EnhancedPGNParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ParseContext;
  class Pgn_databaseContext;
  class PgnContext;
  class Tag_pairsContext;
  class Tag_pairContext;
  class Tag_keyContext;
  class Tag_valueContext;
  class Move_textContext;
  class Game_terminationContext;
  class White_winsContext;
  class Black_winsContext;
  class DrawContext;
  class Unknown_endingContext;
  class Move_text_itemContext;
  class Turn_itemContext;
  class NagContext;
  class CommentContext;
  class Eol_commentContext;
  class Eol_comment_bodyContext;
  class TurnContext;
  class Alternate_lineContext;
  class Move_numContext;
  class SanContext;
  class Check_likeContext;
  class CheckContext;
  class Double_checkContext;
  class CheckmateContext;
  class Move_analysisContext;
  class BlunderContext;
  class MistakeContext;
  class Dubious_moveContext;
  class Interesting_moveContext;
  class Good_moveContext;
  class Brilliant_moveContext;
  class CaptureContext;
  class Pawn_captureContext;
  class Piece_captureContext;
  class Pawn_moveContext;
  class PromotionContext;
  class PieceContext;
  class Piece_moveContext;
  class CastleContext;
  class Block_commentContext;
  class Block_comment_bodyContext;
  class Block_comment_textContext;
  class CommandContext;
  class Command_idContext;
  class Command_paramsContext; 

  class  ParseContext : public antlr4::ParserRuleContext {
  public:
    ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pgn_databaseContext *pgn_database();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParseContext* parse();

  class  Pgn_databaseContext : public antlr4::ParserRuleContext {
  public:
    Pgn_databaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PgnContext *> pgn();
    PgnContext* pgn(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pgn_databaseContext* pgn_database();

  class  PgnContext : public antlr4::ParserRuleContext {
  public:
    PgnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Move_textContext *move_text();
    Tag_pairsContext *tag_pairs();
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PgnContext* pgn();

  class  Tag_pairsContext : public antlr4::ParserRuleContext {
  public:
    Tag_pairsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Tag_pairContext *> tag_pair();
    Tag_pairContext* tag_pair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_pairsContext* tag_pairs();

  class  Tag_pairContext : public antlr4::ParserRuleContext {
  public:
    Tag_pairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAG_START();
    Tag_keyContext *tag_key();
    Tag_valueContext *tag_value();
    antlr4::tree::TerminalNode *TAG_END();
    std::vector<antlr4::tree::TerminalNode *> TAG_SPACE();
    antlr4::tree::TerminalNode* TAG_SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_pairContext* tag_pair();

  class  Tag_keyContext : public antlr4::ParserRuleContext {
  public:
    Tag_keyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAG_KEY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_keyContext* tag_key();

  class  Tag_valueContext : public antlr4::ParserRuleContext {
  public:
    Tag_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAG_VALUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_valueContext* tag_value();

  class  Move_textContext : public antlr4::ParserRuleContext {
  public:
    Move_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Game_terminationContext *game_termination();
    std::vector<Move_text_itemContext *> move_text_item();
    Move_text_itemContext* move_text_item(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Move_textContext* move_text();

  class  Game_terminationContext : public antlr4::ParserRuleContext {
  public:
    Game_terminationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    White_winsContext *white_wins();
    Black_winsContext *black_wins();
    DrawContext *draw();
    Unknown_endingContext *unknown_ending();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Game_terminationContext* game_termination();

  class  White_winsContext : public antlr4::ParserRuleContext {
  public:
    White_winsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHITE_WINS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  White_winsContext* white_wins();

  class  Black_winsContext : public antlr4::ParserRuleContext {
  public:
    Black_winsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLACK_WINS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Black_winsContext* black_wins();

  class  DrawContext : public antlr4::ParserRuleContext {
  public:
    DrawContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DRAW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DrawContext* draw();

  class  Unknown_endingContext : public antlr4::ParserRuleContext {
  public:
    Unknown_endingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNKOWN_ENDING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unknown_endingContext* unknown_ending();

  class  Move_text_itemContext : public antlr4::ParserRuleContext {
  public:
    Move_text_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TurnContext *turn();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Move_text_itemContext* move_text_item();

  class  Turn_itemContext : public antlr4::ParserRuleContext {
  public:
    Turn_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NagContext *nag();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Turn_itemContext* turn_item();

  class  NagContext : public antlr4::ParserRuleContext {
  public:
    NagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NagContext* nag();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_commentContext *block_comment();
    Eol_commentContext *eol_comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentContext* comment();

  class  Eol_commentContext : public antlr4::ParserRuleContext {
  public:
    Eol_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOL_COMMENT_START();
    Eol_comment_bodyContext *eol_comment_body();
    antlr4::tree::TerminalNode *EOL_COMMENT_END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Eol_commentContext* eol_comment();

  class  Eol_comment_bodyContext : public antlr4::ParserRuleContext {
  public:
    Eol_comment_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOL_COMMENT_TEXT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Eol_comment_bodyContext* eol_comment_body();

  class  TurnContext : public antlr4::ParserRuleContext {
  public:
    TurnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Move_numContext *move_num();
    std::vector<SanContext *> san();
    SanContext* san(size_t i);
    std::vector<Turn_itemContext *> turn_item();
    Turn_itemContext* turn_item(size_t i);
    std::vector<Alternate_lineContext *> alternate_line();
    Alternate_lineContext* alternate_line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TurnContext* turn();

  class  Alternate_lineContext : public antlr4::ParserRuleContext {
  public:
    int number;
    Alternate_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Alternate_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState, int number);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALTERNATE_LINE_START();
    antlr4::tree::TerminalNode *ALTERNATE_LINE_END();
    std::vector<TurnContext *> turn();
    TurnContext* turn(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alternate_lineContext* alternate_line(int number);

  class  Move_numContext : public antlr4::ParserRuleContext {
  public:
    Move_numContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOVE_TEXT_START();
    antlr4::tree::TerminalNode *MOVE_NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Move_numContext* move_num();

  class  SanContext : public antlr4::ParserRuleContext {
  public:
    int number;
    SanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    SanContext(antlr4::ParserRuleContext *parent, size_t invokingState, int number);
    virtual size_t getRuleIndex() const override;
    CaptureContext *capture();
    Check_likeContext *check_like();
    Move_analysisContext *move_analysis();
    Pawn_moveContext *pawn_move();
    Piece_moveContext *piece_move();
    CastleContext *castle();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SanContext* san(int number);

  class  Check_likeContext : public antlr4::ParserRuleContext {
  public:
    Check_likeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Double_checkContext *double_check();
    CheckContext *check();
    CheckmateContext *checkmate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Check_likeContext* check_like();

  class  CheckContext : public antlr4::ParserRuleContext {
  public:
    CheckContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHECK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CheckContext* check();

  class  Double_checkContext : public antlr4::ParserRuleContext {
  public:
    Double_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHECK();
    antlr4::tree::TerminalNode* CHECK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Double_checkContext* double_check();

  class  CheckmateContext : public antlr4::ParserRuleContext {
  public:
    CheckmateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHECKMATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CheckmateContext* checkmate();

  class  Move_analysisContext : public antlr4::ParserRuleContext {
  public:
    Move_analysisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlunderContext *blunder();
    MistakeContext *mistake();
    Dubious_moveContext *dubious_move();
    Interesting_moveContext *interesting_move();
    Good_moveContext *good_move();
    Brilliant_moveContext *brilliant_move();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Move_analysisContext* move_analysis();

  class  BlunderContext : public antlr4::ParserRuleContext {
  public:
    BlunderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLUNDER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlunderContext* blunder();

  class  MistakeContext : public antlr4::ParserRuleContext {
  public:
    MistakeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MISTAKE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MistakeContext* mistake();

  class  Dubious_moveContext : public antlr4::ParserRuleContext {
  public:
    Dubious_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DUBIOUS_MOVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dubious_moveContext* dubious_move();

  class  Interesting_moveContext : public antlr4::ParserRuleContext {
  public:
    Interesting_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERESTING_MOVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interesting_moveContext* interesting_move();

  class  Good_moveContext : public antlr4::ParserRuleContext {
  public:
    Good_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOOD_MOVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Good_moveContext* good_move();

  class  Brilliant_moveContext : public antlr4::ParserRuleContext {
  public:
    Brilliant_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRILLIANT_MOVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Brilliant_moveContext* brilliant_move();

  class  CaptureContext : public antlr4::ParserRuleContext {
  public:
    CaptureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pawn_captureContext *pawn_capture();
    Piece_captureContext *piece_capture();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureContext* capture();

  class  Pawn_captureContext : public antlr4::ParserRuleContext {
  public:
    Pawn_captureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *CAPTURE_MARKER();
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *PROMOTION();
    PieceContext *piece();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pawn_captureContext* pawn_capture();

  class  Piece_captureContext : public antlr4::ParserRuleContext {
  public:
    Piece_captureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PieceContext *piece();
    antlr4::tree::TerminalNode *CAPTURE_MARKER();
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *RANK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Piece_captureContext* piece_capture();

  class  Pawn_moveContext : public antlr4::ParserRuleContext {
  public:
    Pawn_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *PROMOTION();
    PieceContext *piece();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pawn_moveContext* pawn_move();

  class  PromotionContext : public antlr4::ParserRuleContext {
  public:
    PromotionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *PROMOTION();
    PieceContext *piece();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PromotionContext* promotion();

  class  PieceContext : public antlr4::ParserRuleContext {
  public:
    PieceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PIECE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PieceContext* piece();

  class  Piece_moveContext : public antlr4::ParserRuleContext {
  public:
    Piece_moveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PieceContext *piece();
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *RANK();
    antlr4::tree::TerminalNode *FILE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Piece_moveContext* piece_move();

  class  CastleContext : public antlr4::ParserRuleContext {
  public:
    CastleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LONG_CASTLE();
    antlr4::tree::TerminalNode *SHORT_CASTLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastleContext* castle();

  class  Block_commentContext : public antlr4::ParserRuleContext {
  public:
    Block_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_comment_bodyContext *block_comment_body();
    antlr4::tree::TerminalNode *BLOCK_COMMENT_END();
    antlr4::tree::TerminalNode *BLOCK_COMMENT_START();
    antlr4::tree::TerminalNode *MOVE_TEXT_START_WITH_COMMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_commentContext* block_comment();

  class  Block_comment_bodyContext : public antlr4::ParserRuleContext {
  public:
    Block_comment_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Block_comment_textContext *> block_comment_text();
    Block_comment_textContext* block_comment_text(size_t i);
    std::vector<CommandContext *> command();
    CommandContext* command(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_comment_bodyContext* block_comment_body();

  class  Block_comment_textContext : public antlr4::ParserRuleContext {
  public:
    Block_comment_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLOCK_COMMENT_TEXT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_comment_textContext* block_comment_text();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMAND_START();
    Command_idContext *command_id();
    Command_paramsContext *command_params();
    antlr4::tree::TerminalNode *COMMAND_END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandContext* command();

  class  Command_idContext : public antlr4::ParserRuleContext {
  public:
    Command_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMAND_ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Command_idContext* command_id();

  class  Command_paramsContext : public antlr4::ParserRuleContext {
  public:
    Command_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> PARAM_TEXT();
    antlr4::tree::TerminalNode* PARAM_TEXT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Command_paramsContext* command_params();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

