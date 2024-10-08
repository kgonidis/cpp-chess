/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
parser grammar EnhancedPGNParser;

options {   tokenVocab = EnhancedPGNLexer; }

parse
    : pgn_database NEW_LINE* EOF
    ;

pgn_database
    : pgn (NEW_LINE+ pgn)* 
    ;

pgn
    : move_text
    | tag_pairs NEW_LINE+ move_text
    ;

tag_pairs
    : (tag_pair NEW_LINE)+ 
    ;

tag_pair
    : TAG_START tag_key TAG_SPACE+ tag_value TAG_END
    ;

tag_key
    : TAG_KEY
    ;

tag_value
    : TAG_VALUE
    ;

move_text
    : move_text_item* game_termination comment*
    ;

game_termination
    : white_wins
    | black_wins
    | draw
    | unknown_ending
    ;

white_wins
    : WHITE_WINS
    ;

black_wins
    : BLACK_WINS
    ;

draw
    : DRAW
    ;

unknown_ending
    : UNKOWN_ENDING
    ;

move_text_item
    : turn
    | comment
    ;

turn_item
    : nag
    | comment
    ;

nag
    : NAG
    ;

comment
    : block_comment
    | eol_comment
    ;

eol_comment
    : EOL_COMMENT_START eol_comment_body EOL_COMMENT_END
    ;

eol_comment_body
    : EOL_COMMENT_TEXT
    ;

turn
    : turn_item* move_num turn_item* san[0] turn_item* alternate_line[0]*
    turn_item* san[1]? turn_item* alternate_line[1]* turn_item*
    ;

alternate_line [number: int]
    : ALTERNATE_LINE_START turn+ ALTERNATE_LINE_END
    ;

move_num
    : MOVE_TEXT_START
    | MOVE_NUM
    ;

san [number: int]
    : capture check_like? move_analysis?
    | pawn_move check_like? move_analysis?
    | piece_move check_like? move_analysis?
    | castle check_like? move_analysis?
    ;

check_like
    : double_check
    | check
    | checkmate
    ;

check
    : CHECK
    ;

double_check
    : CHECK CHECK
    ;

checkmate
    : CHECKMATE
    ;

move_analysis
    : blunder
    | mistake
    | dubious_move
    | interesting_move
    | good_move
    | brilliant_move
    ;

blunder
    : BLUNDER
    ;

mistake
    : MISTAKE
    ;

dubious_move
    : DUBIOUS_MOVE
    ;

interesting_move
    : INTERESTING_MOVE
    ;

good_move
    : GOOD_MOVE
    ;

brilliant_move
    : BRILLIANT_MOVE
    ;

capture
    : pawn_capture
    | piece_capture
    ;

pawn_capture 
    : FILE CAPTURE_MARKER LOCATION (PROMOTION piece)?
    ;

piece_capture
    : piece FILE? RANK? CAPTURE_MARKER LOCATION
    ;

pawn_move
    : LOCATION (PROMOTION piece)?
    ;

promotion
    : LOCATION PROMOTION piece
    ;

piece
    : PIECE
    ;

piece_move
    : piece RANK? FILE? LOCATION
    ;

castle
    : LONG_CASTLE
    | SHORT_CASTLE
    ;

block_comment
    : (BLOCK_COMMENT_START|MOVE_TEXT_START_WITH_COMMENT) block_comment_body BLOCK_COMMENT_END
    ;

block_comment_body
    : block_comment_text? command* block_comment_text?
    ;

block_comment_text
    : BLOCK_COMMENT_TEXT
    ;

command
    : COMMAND_START command_id command_params COMMAND_END
    ;

command_id
    : COMMAND_ID
    ;

command_params
    : PARAM_TEXT (COMMA PARAM_TEXT)*
    ;
