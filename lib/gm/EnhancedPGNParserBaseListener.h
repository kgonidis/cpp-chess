
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "EnhancedPGNParserListener.h"


/**
 * This class provides an empty implementation of EnhancedPGNParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  EnhancedPGNParserBaseListener : public EnhancedPGNParserListener {
public:

  virtual void enterParse(EnhancedPGNParser::ParseContext * /*ctx*/) override { }
  virtual void exitParse(EnhancedPGNParser::ParseContext * /*ctx*/) override { }

  virtual void enterPgn_database(EnhancedPGNParser::Pgn_databaseContext * /*ctx*/) override { }
  virtual void exitPgn_database(EnhancedPGNParser::Pgn_databaseContext * /*ctx*/) override { }

  virtual void enterPgn(EnhancedPGNParser::PgnContext * /*ctx*/) override { }
  virtual void exitPgn(EnhancedPGNParser::PgnContext * /*ctx*/) override { }

  virtual void enterTag_pairs(EnhancedPGNParser::Tag_pairsContext * /*ctx*/) override { }
  virtual void exitTag_pairs(EnhancedPGNParser::Tag_pairsContext * /*ctx*/) override { }

  virtual void enterTag_pair(EnhancedPGNParser::Tag_pairContext * /*ctx*/) override { }
  virtual void exitTag_pair(EnhancedPGNParser::Tag_pairContext * /*ctx*/) override { }

  virtual void enterTag_key(EnhancedPGNParser::Tag_keyContext * /*ctx*/) override { }
  virtual void exitTag_key(EnhancedPGNParser::Tag_keyContext * /*ctx*/) override { }

  virtual void enterTag_value(EnhancedPGNParser::Tag_valueContext * /*ctx*/) override { }
  virtual void exitTag_value(EnhancedPGNParser::Tag_valueContext * /*ctx*/) override { }

  virtual void enterMove_text(EnhancedPGNParser::Move_textContext * /*ctx*/) override { }
  virtual void exitMove_text(EnhancedPGNParser::Move_textContext * /*ctx*/) override { }

  virtual void enterGame_termination(EnhancedPGNParser::Game_terminationContext * /*ctx*/) override { }
  virtual void exitGame_termination(EnhancedPGNParser::Game_terminationContext * /*ctx*/) override { }

  virtual void enterWhite_wins(EnhancedPGNParser::White_winsContext * /*ctx*/) override { }
  virtual void exitWhite_wins(EnhancedPGNParser::White_winsContext * /*ctx*/) override { }

  virtual void enterBlack_wins(EnhancedPGNParser::Black_winsContext * /*ctx*/) override { }
  virtual void exitBlack_wins(EnhancedPGNParser::Black_winsContext * /*ctx*/) override { }

  virtual void enterDraw(EnhancedPGNParser::DrawContext * /*ctx*/) override { }
  virtual void exitDraw(EnhancedPGNParser::DrawContext * /*ctx*/) override { }

  virtual void enterUnknown_ending(EnhancedPGNParser::Unknown_endingContext * /*ctx*/) override { }
  virtual void exitUnknown_ending(EnhancedPGNParser::Unknown_endingContext * /*ctx*/) override { }

  virtual void enterMove_text_item(EnhancedPGNParser::Move_text_itemContext * /*ctx*/) override { }
  virtual void exitMove_text_item(EnhancedPGNParser::Move_text_itemContext * /*ctx*/) override { }

  virtual void enterTurn_item(EnhancedPGNParser::Turn_itemContext * /*ctx*/) override { }
  virtual void exitTurn_item(EnhancedPGNParser::Turn_itemContext * /*ctx*/) override { }

  virtual void enterNag(EnhancedPGNParser::NagContext * /*ctx*/) override { }
  virtual void exitNag(EnhancedPGNParser::NagContext * /*ctx*/) override { }

  virtual void enterComment(EnhancedPGNParser::CommentContext * /*ctx*/) override { }
  virtual void exitComment(EnhancedPGNParser::CommentContext * /*ctx*/) override { }

  virtual void enterEol_comment(EnhancedPGNParser::Eol_commentContext * /*ctx*/) override { }
  virtual void exitEol_comment(EnhancedPGNParser::Eol_commentContext * /*ctx*/) override { }

  virtual void enterEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext * /*ctx*/) override { }
  virtual void exitEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext * /*ctx*/) override { }

  virtual void enterTurn(EnhancedPGNParser::TurnContext * /*ctx*/) override { }
  virtual void exitTurn(EnhancedPGNParser::TurnContext * /*ctx*/) override { }

  virtual void enterAlternate_line(EnhancedPGNParser::Alternate_lineContext * /*ctx*/) override { }
  virtual void exitAlternate_line(EnhancedPGNParser::Alternate_lineContext * /*ctx*/) override { }

  virtual void enterMove_num(EnhancedPGNParser::Move_numContext * /*ctx*/) override { }
  virtual void exitMove_num(EnhancedPGNParser::Move_numContext * /*ctx*/) override { }

  virtual void enterSan(EnhancedPGNParser::SanContext * /*ctx*/) override { }
  virtual void exitSan(EnhancedPGNParser::SanContext * /*ctx*/) override { }

  virtual void enterCheck_like(EnhancedPGNParser::Check_likeContext * /*ctx*/) override { }
  virtual void exitCheck_like(EnhancedPGNParser::Check_likeContext * /*ctx*/) override { }

  virtual void enterCheck(EnhancedPGNParser::CheckContext * /*ctx*/) override { }
  virtual void exitCheck(EnhancedPGNParser::CheckContext * /*ctx*/) override { }

  virtual void enterDouble_check(EnhancedPGNParser::Double_checkContext * /*ctx*/) override { }
  virtual void exitDouble_check(EnhancedPGNParser::Double_checkContext * /*ctx*/) override { }

  virtual void enterCheckmate(EnhancedPGNParser::CheckmateContext * /*ctx*/) override { }
  virtual void exitCheckmate(EnhancedPGNParser::CheckmateContext * /*ctx*/) override { }

  virtual void enterMove_analysis(EnhancedPGNParser::Move_analysisContext * /*ctx*/) override { }
  virtual void exitMove_analysis(EnhancedPGNParser::Move_analysisContext * /*ctx*/) override { }

  virtual void enterBlunder(EnhancedPGNParser::BlunderContext * /*ctx*/) override { }
  virtual void exitBlunder(EnhancedPGNParser::BlunderContext * /*ctx*/) override { }

  virtual void enterMistake(EnhancedPGNParser::MistakeContext * /*ctx*/) override { }
  virtual void exitMistake(EnhancedPGNParser::MistakeContext * /*ctx*/) override { }

  virtual void enterDubious_move(EnhancedPGNParser::Dubious_moveContext * /*ctx*/) override { }
  virtual void exitDubious_move(EnhancedPGNParser::Dubious_moveContext * /*ctx*/) override { }

  virtual void enterInteresting_move(EnhancedPGNParser::Interesting_moveContext * /*ctx*/) override { }
  virtual void exitInteresting_move(EnhancedPGNParser::Interesting_moveContext * /*ctx*/) override { }

  virtual void enterGood_move(EnhancedPGNParser::Good_moveContext * /*ctx*/) override { }
  virtual void exitGood_move(EnhancedPGNParser::Good_moveContext * /*ctx*/) override { }

  virtual void enterBrilliant_move(EnhancedPGNParser::Brilliant_moveContext * /*ctx*/) override { }
  virtual void exitBrilliant_move(EnhancedPGNParser::Brilliant_moveContext * /*ctx*/) override { }

  virtual void enterCapture(EnhancedPGNParser::CaptureContext * /*ctx*/) override { }
  virtual void exitCapture(EnhancedPGNParser::CaptureContext * /*ctx*/) override { }

  virtual void enterPawn_capture(EnhancedPGNParser::Pawn_captureContext * /*ctx*/) override { }
  virtual void exitPawn_capture(EnhancedPGNParser::Pawn_captureContext * /*ctx*/) override { }

  virtual void enterPiece_capture(EnhancedPGNParser::Piece_captureContext * /*ctx*/) override { }
  virtual void exitPiece_capture(EnhancedPGNParser::Piece_captureContext * /*ctx*/) override { }

  virtual void enterPawn_move(EnhancedPGNParser::Pawn_moveContext * /*ctx*/) override { }
  virtual void exitPawn_move(EnhancedPGNParser::Pawn_moveContext * /*ctx*/) override { }

  virtual void enterPromotion(EnhancedPGNParser::PromotionContext * /*ctx*/) override { }
  virtual void exitPromotion(EnhancedPGNParser::PromotionContext * /*ctx*/) override { }

  virtual void enterPiece(EnhancedPGNParser::PieceContext * /*ctx*/) override { }
  virtual void exitPiece(EnhancedPGNParser::PieceContext * /*ctx*/) override { }

  virtual void enterPiece_move(EnhancedPGNParser::Piece_moveContext * /*ctx*/) override { }
  virtual void exitPiece_move(EnhancedPGNParser::Piece_moveContext * /*ctx*/) override { }

  virtual void enterCastle(EnhancedPGNParser::CastleContext * /*ctx*/) override { }
  virtual void exitCastle(EnhancedPGNParser::CastleContext * /*ctx*/) override { }

  virtual void enterBlock_comment(EnhancedPGNParser::Block_commentContext * /*ctx*/) override { }
  virtual void exitBlock_comment(EnhancedPGNParser::Block_commentContext * /*ctx*/) override { }

  virtual void enterBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext * /*ctx*/) override { }
  virtual void exitBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext * /*ctx*/) override { }

  virtual void enterBlock_comment_text(EnhancedPGNParser::Block_comment_textContext * /*ctx*/) override { }
  virtual void exitBlock_comment_text(EnhancedPGNParser::Block_comment_textContext * /*ctx*/) override { }

  virtual void enterCommand(EnhancedPGNParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(EnhancedPGNParser::CommandContext * /*ctx*/) override { }

  virtual void enterCommand_id(EnhancedPGNParser::Command_idContext * /*ctx*/) override { }
  virtual void exitCommand_id(EnhancedPGNParser::Command_idContext * /*ctx*/) override { }

  virtual void enterCommand_params(EnhancedPGNParser::Command_paramsContext * /*ctx*/) override { }
  virtual void exitCommand_params(EnhancedPGNParser::Command_paramsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

