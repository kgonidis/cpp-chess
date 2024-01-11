
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "EnhancedPGNParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by EnhancedPGNParser.
 */
class  EnhancedPGNParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by EnhancedPGNParser.
   */
    virtual std::any visitParse(EnhancedPGNParser::ParseContext *context) = 0;

    virtual std::any visitPgn_database(EnhancedPGNParser::Pgn_databaseContext *context) = 0;

    virtual std::any visitPgn(EnhancedPGNParser::PgnContext *context) = 0;

    virtual std::any visitTag_pairs(EnhancedPGNParser::Tag_pairsContext *context) = 0;

    virtual std::any visitTag_pair(EnhancedPGNParser::Tag_pairContext *context) = 0;

    virtual std::any visitTag_key(EnhancedPGNParser::Tag_keyContext *context) = 0;

    virtual std::any visitTag_value(EnhancedPGNParser::Tag_valueContext *context) = 0;

    virtual std::any visitMove_text(EnhancedPGNParser::Move_textContext *context) = 0;

    virtual std::any visitGame_termination(EnhancedPGNParser::Game_terminationContext *context) = 0;

    virtual std::any visitWhite_wins(EnhancedPGNParser::White_winsContext *context) = 0;

    virtual std::any visitBlack_wins(EnhancedPGNParser::Black_winsContext *context) = 0;

    virtual std::any visitDraw(EnhancedPGNParser::DrawContext *context) = 0;

    virtual std::any visitUnknown_ending(EnhancedPGNParser::Unknown_endingContext *context) = 0;

    virtual std::any visitMove_text_item(EnhancedPGNParser::Move_text_itemContext *context) = 0;

    virtual std::any visitTurn_item(EnhancedPGNParser::Turn_itemContext *context) = 0;

    virtual std::any visitNag(EnhancedPGNParser::NagContext *context) = 0;

    virtual std::any visitComment(EnhancedPGNParser::CommentContext *context) = 0;

    virtual std::any visitEol_comment(EnhancedPGNParser::Eol_commentContext *context) = 0;

    virtual std::any visitEol_comment_body(EnhancedPGNParser::Eol_comment_bodyContext *context) = 0;

    virtual std::any visitTurn(EnhancedPGNParser::TurnContext *context) = 0;

    virtual std::any visitAlternate_line(EnhancedPGNParser::Alternate_lineContext *context) = 0;

    virtual std::any visitMove_num(EnhancedPGNParser::Move_numContext *context) = 0;

    virtual std::any visitSan(EnhancedPGNParser::SanContext *context) = 0;

    virtual std::any visitCheck_like(EnhancedPGNParser::Check_likeContext *context) = 0;

    virtual std::any visitCheck(EnhancedPGNParser::CheckContext *context) = 0;

    virtual std::any visitDouble_check(EnhancedPGNParser::Double_checkContext *context) = 0;

    virtual std::any visitCheckmate(EnhancedPGNParser::CheckmateContext *context) = 0;

    virtual std::any visitMove_analysis(EnhancedPGNParser::Move_analysisContext *context) = 0;

    virtual std::any visitBlunder(EnhancedPGNParser::BlunderContext *context) = 0;

    virtual std::any visitMistake(EnhancedPGNParser::MistakeContext *context) = 0;

    virtual std::any visitDubious_move(EnhancedPGNParser::Dubious_moveContext *context) = 0;

    virtual std::any visitInteresting_move(EnhancedPGNParser::Interesting_moveContext *context) = 0;

    virtual std::any visitGood_move(EnhancedPGNParser::Good_moveContext *context) = 0;

    virtual std::any visitBrilliant_move(EnhancedPGNParser::Brilliant_moveContext *context) = 0;

    virtual std::any visitCapture(EnhancedPGNParser::CaptureContext *context) = 0;

    virtual std::any visitPawn_capture(EnhancedPGNParser::Pawn_captureContext *context) = 0;

    virtual std::any visitPiece_capture(EnhancedPGNParser::Piece_captureContext *context) = 0;

    virtual std::any visitPawn_move(EnhancedPGNParser::Pawn_moveContext *context) = 0;

    virtual std::any visitPromotion(EnhancedPGNParser::PromotionContext *context) = 0;

    virtual std::any visitPiece(EnhancedPGNParser::PieceContext *context) = 0;

    virtual std::any visitPiece_move(EnhancedPGNParser::Piece_moveContext *context) = 0;

    virtual std::any visitCastle(EnhancedPGNParser::CastleContext *context) = 0;

    virtual std::any visitBlock_comment(EnhancedPGNParser::Block_commentContext *context) = 0;

    virtual std::any visitBlock_comment_body(EnhancedPGNParser::Block_comment_bodyContext *context) = 0;

    virtual std::any visitBlock_comment_text(EnhancedPGNParser::Block_comment_textContext *context) = 0;

    virtual std::any visitCommand(EnhancedPGNParser::CommandContext *context) = 0;

    virtual std::any visitCommand_id(EnhancedPGNParser::Command_idContext *context) = 0;

    virtual std::any visitCommand_params(EnhancedPGNParser::Command_paramsContext *context) = 0;


};

