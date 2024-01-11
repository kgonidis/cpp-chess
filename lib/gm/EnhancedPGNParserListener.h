
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "EnhancedPGNParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by EnhancedPGNParser.
 */
class  EnhancedPGNParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParse(EnhancedPGNParser::ParseContext *ctx) = 0;
  virtual void exitParse(EnhancedPGNParser::ParseContext *ctx) = 0;

  virtual void enterPgn_database(EnhancedPGNParser::Pgn_databaseContext *ctx) = 0;
  virtual void exitPgn_database(EnhancedPGNParser::Pgn_databaseContext *ctx) = 0;

  virtual void enterPgn(EnhancedPGNParser::PgnContext *ctx) = 0;
  virtual void exitPgn(EnhancedPGNParser::PgnContext *ctx) = 0;

  virtual void enterTag_pairs(EnhancedPGNParser::Tag_pairsContext *ctx) = 0;
  virtual void exitTag_pairs(EnhancedPGNParser::Tag_pairsContext *ctx) = 0;

  virtual void enterTag_pair(EnhancedPGNParser::Tag_pairContext *ctx) = 0;
  virtual void exitTag_pair(EnhancedPGNParser::Tag_pairContext *ctx) = 0;

  virtual void enterTag_key(EnhancedPGNParser::Tag_keyContext *ctx) = 0;
  virtual void exitTag_key(EnhancedPGNParser::Tag_keyContext *ctx) = 0;

  virtual void enterTag_value(EnhancedPGNParser::Tag_valueContext *ctx) = 0;
  virtual void exitTag_value(EnhancedPGNParser::Tag_valueContext *ctx) = 0;

  virtual void enterMove_text(EnhancedPGNParser::Move_textContext *ctx) = 0;
  virtual void exitMove_text(EnhancedPGNParser::Move_textContext *ctx) = 0;

  virtual void enterGame_termination(EnhancedPGNParser::Game_terminationContext *ctx) = 0;
  virtual void exitGame_termination(EnhancedPGNParser::Game_terminationContext *ctx) = 0;

  virtual void enterWhite_wins(EnhancedPGNParser::White_winsContext *ctx) = 0;
  virtual void exitWhite_wins(EnhancedPGNParser::White_winsContext *ctx) = 0;

  virtual void enterBlack_wins(EnhancedPGNParser::Black_winsContext *ctx) = 0;
  virtual void exitBlack_wins(EnhancedPGNParser::Black_winsContext *ctx) = 0;

  virtual void enterDraw(EnhancedPGNParser::DrawContext *ctx) = 0;
  virtual void exitDraw(EnhancedPGNParser::DrawContext *ctx) = 0;

  virtual void enterUnknown_ending(EnhancedPGNParser::Unknown_endingContext *ctx) = 0;
  virtual void exitUnknown_ending(EnhancedPGNParser::Unknown_endingContext *ctx) = 0;

  virtual void enterMove_text_item(EnhancedPGNParser::Move_text_itemContext *ctx) = 0;
  virtual void exitMove_text_item(EnhancedPGNParser::Move_text_itemContext *ctx) = 0;

  virtual void enterTurn_item(EnhancedPGNParser::Turn_itemContext *ctx) = 0;
  virtual void exitTurn_item(EnhancedPGNParser::Turn_itemContext *ctx) = 0;

  virtual void enterNag(EnhancedPGNParser::NagContext *ctx) = 0;
  virtual void exitNag(EnhancedPGNParser::NagContext *ctx) = 0;

  virtual void enterComment(EnhancedPGNParser::CommentContext *ctx) = 0;
  virtual void exitComment(EnhancedPGNParser::CommentContext *ctx) = 0;

  virtual void enterEol_comment(EnhancedPGNParser::Eol_commentContext *ctx) = 0;
  virtual void exitEol_comment(EnhancedPGNParser::Eol_commentContext *ctx) = 0;

  virtual void enterEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext *ctx) = 0;
  virtual void exitEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext *ctx) = 0;

  virtual void enterTurn(EnhancedPGNParser::TurnContext *ctx) = 0;
  virtual void exitTurn(EnhancedPGNParser::TurnContext *ctx) = 0;

  virtual void enterAlternate_line(EnhancedPGNParser::Alternate_lineContext *ctx) = 0;
  virtual void exitAlternate_line(EnhancedPGNParser::Alternate_lineContext *ctx) = 0;

  virtual void enterMove_num(EnhancedPGNParser::Move_numContext *ctx) = 0;
  virtual void exitMove_num(EnhancedPGNParser::Move_numContext *ctx) = 0;

  virtual void enterSan(EnhancedPGNParser::SanContext *ctx) = 0;
  virtual void exitSan(EnhancedPGNParser::SanContext *ctx) = 0;

  virtual void enterCheck_like(EnhancedPGNParser::Check_likeContext *ctx) = 0;
  virtual void exitCheck_like(EnhancedPGNParser::Check_likeContext *ctx) = 0;

  virtual void enterCheck(EnhancedPGNParser::CheckContext *ctx) = 0;
  virtual void exitCheck(EnhancedPGNParser::CheckContext *ctx) = 0;

  virtual void enterDouble_check(EnhancedPGNParser::Double_checkContext *ctx) = 0;
  virtual void exitDouble_check(EnhancedPGNParser::Double_checkContext *ctx) = 0;

  virtual void enterCheckmate(EnhancedPGNParser::CheckmateContext *ctx) = 0;
  virtual void exitCheckmate(EnhancedPGNParser::CheckmateContext *ctx) = 0;

  virtual void enterMove_analysis(EnhancedPGNParser::Move_analysisContext *ctx) = 0;
  virtual void exitMove_analysis(EnhancedPGNParser::Move_analysisContext *ctx) = 0;

  virtual void enterBlunder(EnhancedPGNParser::BlunderContext *ctx) = 0;
  virtual void exitBlunder(EnhancedPGNParser::BlunderContext *ctx) = 0;

  virtual void enterMistake(EnhancedPGNParser::MistakeContext *ctx) = 0;
  virtual void exitMistake(EnhancedPGNParser::MistakeContext *ctx) = 0;

  virtual void enterDubious_move(EnhancedPGNParser::Dubious_moveContext *ctx) = 0;
  virtual void exitDubious_move(EnhancedPGNParser::Dubious_moveContext *ctx) = 0;

  virtual void enterInteresting_move(EnhancedPGNParser::Interesting_moveContext *ctx) = 0;
  virtual void exitInteresting_move(EnhancedPGNParser::Interesting_moveContext *ctx) = 0;

  virtual void enterGood_move(EnhancedPGNParser::Good_moveContext *ctx) = 0;
  virtual void exitGood_move(EnhancedPGNParser::Good_moveContext *ctx) = 0;

  virtual void enterBrilliant_move(EnhancedPGNParser::Brilliant_moveContext *ctx) = 0;
  virtual void exitBrilliant_move(EnhancedPGNParser::Brilliant_moveContext *ctx) = 0;

  virtual void enterCapture(EnhancedPGNParser::CaptureContext *ctx) = 0;
  virtual void exitCapture(EnhancedPGNParser::CaptureContext *ctx) = 0;

  virtual void enterPawn_capture(EnhancedPGNParser::Pawn_captureContext *ctx) = 0;
  virtual void exitPawn_capture(EnhancedPGNParser::Pawn_captureContext *ctx) = 0;

  virtual void enterPiece_capture(EnhancedPGNParser::Piece_captureContext *ctx) = 0;
  virtual void exitPiece_capture(EnhancedPGNParser::Piece_captureContext *ctx) = 0;

  virtual void enterPawn_move(EnhancedPGNParser::Pawn_moveContext *ctx) = 0;
  virtual void exitPawn_move(EnhancedPGNParser::Pawn_moveContext *ctx) = 0;

  virtual void enterPromotion(EnhancedPGNParser::PromotionContext *ctx) = 0;
  virtual void exitPromotion(EnhancedPGNParser::PromotionContext *ctx) = 0;

  virtual void enterPiece(EnhancedPGNParser::PieceContext *ctx) = 0;
  virtual void exitPiece(EnhancedPGNParser::PieceContext *ctx) = 0;

  virtual void enterPiece_move(EnhancedPGNParser::Piece_moveContext *ctx) = 0;
  virtual void exitPiece_move(EnhancedPGNParser::Piece_moveContext *ctx) = 0;

  virtual void enterCastle(EnhancedPGNParser::CastleContext *ctx) = 0;
  virtual void exitCastle(EnhancedPGNParser::CastleContext *ctx) = 0;

  virtual void enterBlock_comment(EnhancedPGNParser::Block_commentContext *ctx) = 0;
  virtual void exitBlock_comment(EnhancedPGNParser::Block_commentContext *ctx) = 0;

  virtual void enterBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext *ctx) = 0;
  virtual void exitBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext *ctx) = 0;

  virtual void enterBlock_comment_text(EnhancedPGNParser::Block_comment_textContext *ctx) = 0;
  virtual void exitBlock_comment_text(EnhancedPGNParser::Block_comment_textContext *ctx) = 0;

  virtual void enterCommand(EnhancedPGNParser::CommandContext *ctx) = 0;
  virtual void exitCommand(EnhancedPGNParser::CommandContext *ctx) = 0;

  virtual void enterCommand_id(EnhancedPGNParser::Command_idContext *ctx) = 0;
  virtual void exitCommand_id(EnhancedPGNParser::Command_idContext *ctx) = 0;

  virtual void enterCommand_params(EnhancedPGNParser::Command_paramsContext *ctx) = 0;
  virtual void exitCommand_params(EnhancedPGNParser::Command_paramsContext *ctx) = 0;


};

