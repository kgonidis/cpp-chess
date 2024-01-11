
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "EnhancedPGNParserVisitor.h"


/**
 * This class provides an empty implementation of EnhancedPGNParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  EnhancedPGNParserBaseVisitor : public EnhancedPGNParserVisitor {
public:

  virtual std::any visitParse(EnhancedPGNParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPgn_database(EnhancedPGNParser::Pgn_databaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPgn(EnhancedPGNParser::PgnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_pairs(EnhancedPGNParser::Tag_pairsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_pair(EnhancedPGNParser::Tag_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_key(EnhancedPGNParser::Tag_keyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_value(EnhancedPGNParser::Tag_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMove_text(EnhancedPGNParser::Move_textContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGame_termination(EnhancedPGNParser::Game_terminationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhite_wins(EnhancedPGNParser::White_winsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlack_wins(EnhancedPGNParser::Black_winsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDraw(EnhancedPGNParser::DrawContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnknown_ending(EnhancedPGNParser::Unknown_endingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMove_text_item(EnhancedPGNParser::Move_text_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTurn_item(EnhancedPGNParser::Turn_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNag(EnhancedPGNParser::NagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComment(EnhancedPGNParser::CommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEol_comment(EnhancedPGNParser::Eol_commentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTurn(EnhancedPGNParser::TurnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlternate_line(EnhancedPGNParser::Alternate_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMove_num(EnhancedPGNParser::Move_numContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSan(EnhancedPGNParser::SanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheck_like(EnhancedPGNParser::Check_likeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheck(EnhancedPGNParser::CheckContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDouble_check(EnhancedPGNParser::Double_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheckmate(EnhancedPGNParser::CheckmateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMove_analysis(EnhancedPGNParser::Move_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlunder(EnhancedPGNParser::BlunderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMistake(EnhancedPGNParser::MistakeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDubious_move(EnhancedPGNParser::Dubious_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteresting_move(EnhancedPGNParser::Interesting_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGood_move(EnhancedPGNParser::Good_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBrilliant_move(EnhancedPGNParser::Brilliant_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCapture(EnhancedPGNParser::CaptureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPawn_capture(EnhancedPGNParser::Pawn_captureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPiece_capture(EnhancedPGNParser::Piece_captureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPawn_move(EnhancedPGNParser::Pawn_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPromotion(EnhancedPGNParser::PromotionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPiece(EnhancedPGNParser::PieceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPiece_move(EnhancedPGNParser::Piece_moveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCastle(EnhancedPGNParser::CastleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_comment(EnhancedPGNParser::Block_commentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_comment_text(EnhancedPGNParser::Block_comment_textContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommand(EnhancedPGNParser::CommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommand_id(EnhancedPGNParser::Command_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommand_params(EnhancedPGNParser::Command_paramsContext *ctx) override {
    return visitChildren(ctx);
  }


};

