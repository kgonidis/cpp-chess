
// Generated from EnhancedPGNParser.g4 by ANTLR 4.13.1


#include "EnhancedPGNParserListener.h"

#include "EnhancedPGNParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct EnhancedPGNParserStaticData final {
  EnhancedPGNParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  EnhancedPGNParserStaticData(const EnhancedPGNParserStaticData&) = delete;
  EnhancedPGNParserStaticData(EnhancedPGNParserStaticData&&) = delete;
  EnhancedPGNParserStaticData& operator=(const EnhancedPGNParserStaticData&) = delete;
  EnhancedPGNParserStaticData& operator=(EnhancedPGNParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag enhancedpgnparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
EnhancedPGNParserStaticData *enhancedpgnparserParserStaticData = nullptr;

void enhancedpgnparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (enhancedpgnparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(enhancedpgnparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<EnhancedPGNParserStaticData>(
    std::vector<std::string>{
      "parse", "pgn_database", "pgn", "tag_pairs", "tag_pair", "tag_key", 
      "tag_value", "move_text", "game_termination", "white_wins", "black_wins", 
      "draw", "unknown_ending", "move_text_item", "turn_item", "nag", "comment", 
      "eol_comment", "eol_comment_body", "turn", "alternate_line", "move_num", 
      "san", "check_like", "check", "double_check", "checkmate", "move_analysis", 
      "blunder", "mistake", "dubious_move", "interesting_move", "good_move", 
      "brilliant_move", "capture", "pawn_capture", "piece_capture", "pawn_move", 
      "promotion", "piece", "piece_move", "castle", "block_comment", "block_comment_body", 
      "block_comment_text", "command", "command_id", "command_params"
    },
    std::vector<std::string>{
      "", "'['", "", "", "", "", "", "", "", "' '", "';'", "", "'{'", "", 
      "", "", "'='", "", "", "'O-O'", "'O-O-O'", "'x'", "'('", "')'", "'\\u003F\\u003F'", 
      "'\\u003F'", "'\\u003F!'", "'!\\u003F'", "'!'", "'!!'", "'+'", "'#'", 
      "'1-0'", "'0-1'", "'1/2-1/2'", "'*'", "", "", "'\\n'", "'[%'", "'}'", 
      "", "", "", "','"
    },
    std::vector<std::string>{
      "", "TAG_START", "STRING", "MOVE_TEXT_START", "MOVE_TEXT_START_WITH_COMMENT", 
      "NEW_LINE", "TAG_END", "TAG_VALUE", "TAG_KEY", "TAG_SPACE", "EOL_COMMENT_START", 
      "MOVE_NUM", "BLOCK_COMMENT_START", "WS", "PIECE", "LOCATION", "PROMOTION", 
      "RANK", "FILE", "SHORT_CASTLE", "LONG_CASTLE", "CAPTURE_MARKER", "ALTERNATE_LINE_START", 
      "ALTERNATE_LINE_END", "BLUNDER", "MISTAKE", "DUBIOUS_MOVE", "INTERESTING_MOVE", 
      "GOOD_MOVE", "BRILLIANT_MOVE", "CHECK", "CHECKMATE", "WHITE_WINS", 
      "BLACK_WINS", "DRAW", "UNKOWN_ENDING", "NAG", "EOL_COMMENT_TEXT", 
      "EOL_COMMENT_END", "COMMAND_START", "BLOCK_COMMENT_END", "BLOCK_COMMENT_TEXT", 
      "COMMAND_ID", "COMMAND_END", "COMMA", "PARAM_TEXT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,398,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,1,0,1,0,5,0,99,8,
  	0,10,0,12,0,102,9,0,1,0,1,0,1,1,1,1,4,1,108,8,1,11,1,12,1,109,1,1,5,1,
  	113,8,1,10,1,12,1,116,9,1,1,2,1,2,1,2,4,2,121,8,2,11,2,12,2,122,1,2,1,
  	2,3,2,127,8,2,1,3,1,3,1,3,4,3,132,8,3,11,3,12,3,133,1,4,1,4,1,4,4,4,139,
  	8,4,11,4,12,4,140,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,7,5,7,151,8,7,10,7,12,
  	7,154,9,7,1,7,1,7,5,7,158,8,7,10,7,12,7,161,9,7,1,8,1,8,1,8,1,8,3,8,167,
  	8,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,3,13,179,8,13,1,14,
  	1,14,3,14,183,8,14,1,15,1,15,1,16,1,16,3,16,189,8,16,1,17,1,17,1,17,1,
  	17,1,18,1,18,1,19,5,19,198,8,19,10,19,12,19,201,9,19,1,19,1,19,5,19,205,
  	8,19,10,19,12,19,208,9,19,1,19,1,19,5,19,212,8,19,10,19,12,19,215,9,19,
  	1,19,5,19,218,8,19,10,19,12,19,221,9,19,1,19,5,19,224,8,19,10,19,12,19,
  	227,9,19,1,19,3,19,230,8,19,1,19,5,19,233,8,19,10,19,12,19,236,9,19,1,
  	19,5,19,239,8,19,10,19,12,19,242,9,19,1,19,5,19,245,8,19,10,19,12,19,
  	248,9,19,1,20,1,20,4,20,252,8,20,11,20,12,20,253,1,20,1,20,1,21,1,21,
  	1,22,1,22,3,22,262,8,22,1,22,3,22,265,8,22,1,22,1,22,3,22,269,8,22,1,
  	22,3,22,272,8,22,1,22,1,22,3,22,276,8,22,1,22,3,22,279,8,22,1,22,1,22,
  	3,22,283,8,22,1,22,3,22,286,8,22,3,22,288,8,22,1,23,1,23,1,23,3,23,293,
  	8,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,
  	3,27,308,8,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,
  	1,33,1,34,1,34,3,34,324,8,34,1,35,1,35,1,35,1,35,1,35,3,35,331,8,35,1,
  	36,1,36,3,36,335,8,36,1,36,3,36,338,8,36,1,36,1,36,1,36,1,37,1,37,1,37,
  	3,37,346,8,37,1,38,1,38,1,38,1,38,1,39,1,39,1,40,1,40,3,40,356,8,40,1,
  	40,3,40,359,8,40,1,40,1,40,1,41,1,41,1,42,1,42,1,42,1,42,1,43,3,43,370,
  	8,43,1,43,5,43,373,8,43,10,43,12,43,376,9,43,1,43,3,43,379,8,43,1,44,
  	1,44,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,47,1,47,1,47,5,47,393,8,47,
  	10,47,12,47,396,9,47,1,47,0,0,48,0,2,4,6,8,10,12,14,16,18,20,22,24,26,
  	28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,
  	74,76,78,80,82,84,86,88,90,92,94,0,3,2,0,3,3,11,11,1,0,19,20,2,0,4,4,
  	12,12,403,0,96,1,0,0,0,2,105,1,0,0,0,4,126,1,0,0,0,6,131,1,0,0,0,8,135,
  	1,0,0,0,10,145,1,0,0,0,12,147,1,0,0,0,14,152,1,0,0,0,16,166,1,0,0,0,18,
  	168,1,0,0,0,20,170,1,0,0,0,22,172,1,0,0,0,24,174,1,0,0,0,26,178,1,0,0,
  	0,28,182,1,0,0,0,30,184,1,0,0,0,32,188,1,0,0,0,34,190,1,0,0,0,36,194,
  	1,0,0,0,38,199,1,0,0,0,40,249,1,0,0,0,42,257,1,0,0,0,44,287,1,0,0,0,46,
  	292,1,0,0,0,48,294,1,0,0,0,50,296,1,0,0,0,52,299,1,0,0,0,54,307,1,0,0,
  	0,56,309,1,0,0,0,58,311,1,0,0,0,60,313,1,0,0,0,62,315,1,0,0,0,64,317,
  	1,0,0,0,66,319,1,0,0,0,68,323,1,0,0,0,70,325,1,0,0,0,72,332,1,0,0,0,74,
  	342,1,0,0,0,76,347,1,0,0,0,78,351,1,0,0,0,80,353,1,0,0,0,82,362,1,0,0,
  	0,84,364,1,0,0,0,86,369,1,0,0,0,88,380,1,0,0,0,90,382,1,0,0,0,92,387,
  	1,0,0,0,94,389,1,0,0,0,96,100,3,2,1,0,97,99,5,5,0,0,98,97,1,0,0,0,99,
  	102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,103,1,0,0,0,102,100,1,
  	0,0,0,103,104,5,0,0,1,104,1,1,0,0,0,105,114,3,4,2,0,106,108,5,5,0,0,107,
  	106,1,0,0,0,108,109,1,0,0,0,109,107,1,0,0,0,109,110,1,0,0,0,110,111,1,
  	0,0,0,111,113,3,4,2,0,112,107,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,
  	114,115,1,0,0,0,115,3,1,0,0,0,116,114,1,0,0,0,117,127,3,14,7,0,118,120,
  	3,6,3,0,119,121,5,5,0,0,120,119,1,0,0,0,121,122,1,0,0,0,122,120,1,0,0,
  	0,122,123,1,0,0,0,123,124,1,0,0,0,124,125,3,14,7,0,125,127,1,0,0,0,126,
  	117,1,0,0,0,126,118,1,0,0,0,127,5,1,0,0,0,128,129,3,8,4,0,129,130,5,5,
  	0,0,130,132,1,0,0,0,131,128,1,0,0,0,132,133,1,0,0,0,133,131,1,0,0,0,133,
  	134,1,0,0,0,134,7,1,0,0,0,135,136,5,1,0,0,136,138,3,10,5,0,137,139,5,
  	9,0,0,138,137,1,0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,0,
  	141,142,1,0,0,0,142,143,3,12,6,0,143,144,5,6,0,0,144,9,1,0,0,0,145,146,
  	5,8,0,0,146,11,1,0,0,0,147,148,5,7,0,0,148,13,1,0,0,0,149,151,3,26,13,
  	0,150,149,1,0,0,0,151,154,1,0,0,0,152,150,1,0,0,0,152,153,1,0,0,0,153,
  	155,1,0,0,0,154,152,1,0,0,0,155,159,3,16,8,0,156,158,3,32,16,0,157,156,
  	1,0,0,0,158,161,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,15,1,0,0,
  	0,161,159,1,0,0,0,162,167,3,18,9,0,163,167,3,20,10,0,164,167,3,22,11,
  	0,165,167,3,24,12,0,166,162,1,0,0,0,166,163,1,0,0,0,166,164,1,0,0,0,166,
  	165,1,0,0,0,167,17,1,0,0,0,168,169,5,32,0,0,169,19,1,0,0,0,170,171,5,
  	33,0,0,171,21,1,0,0,0,172,173,5,34,0,0,173,23,1,0,0,0,174,175,5,35,0,
  	0,175,25,1,0,0,0,176,179,3,38,19,0,177,179,3,32,16,0,178,176,1,0,0,0,
  	178,177,1,0,0,0,179,27,1,0,0,0,180,183,3,30,15,0,181,183,3,32,16,0,182,
  	180,1,0,0,0,182,181,1,0,0,0,183,29,1,0,0,0,184,185,5,36,0,0,185,31,1,
  	0,0,0,186,189,3,84,42,0,187,189,3,34,17,0,188,186,1,0,0,0,188,187,1,0,
  	0,0,189,33,1,0,0,0,190,191,5,10,0,0,191,192,3,36,18,0,192,193,5,38,0,
  	0,193,35,1,0,0,0,194,195,5,37,0,0,195,37,1,0,0,0,196,198,3,28,14,0,197,
  	196,1,0,0,0,198,201,1,0,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,202,1,
  	0,0,0,201,199,1,0,0,0,202,206,3,42,21,0,203,205,3,28,14,0,204,203,1,0,
  	0,0,205,208,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,209,1,0,0,0,208,
  	206,1,0,0,0,209,213,3,44,22,0,210,212,3,28,14,0,211,210,1,0,0,0,212,215,
  	1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,219,1,0,0,0,215,213,1,0,0,
  	0,216,218,3,40,20,0,217,216,1,0,0,0,218,221,1,0,0,0,219,217,1,0,0,0,219,
  	220,1,0,0,0,220,225,1,0,0,0,221,219,1,0,0,0,222,224,3,28,14,0,223,222,
  	1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,229,1,0,0,
  	0,227,225,1,0,0,0,228,230,3,44,22,0,229,228,1,0,0,0,229,230,1,0,0,0,230,
  	234,1,0,0,0,231,233,3,28,14,0,232,231,1,0,0,0,233,236,1,0,0,0,234,232,
  	1,0,0,0,234,235,1,0,0,0,235,240,1,0,0,0,236,234,1,0,0,0,237,239,3,40,
  	20,0,238,237,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,
  	241,246,1,0,0,0,242,240,1,0,0,0,243,245,3,28,14,0,244,243,1,0,0,0,245,
  	248,1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,247,39,1,0,0,0,248,246,1,
  	0,0,0,249,251,5,22,0,0,250,252,3,38,19,0,251,250,1,0,0,0,252,253,1,0,
  	0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,0,255,256,5,23,0,0,
  	256,41,1,0,0,0,257,258,7,0,0,0,258,43,1,0,0,0,259,261,3,68,34,0,260,262,
  	3,46,23,0,261,260,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,0,263,265,3,54,
  	27,0,264,263,1,0,0,0,264,265,1,0,0,0,265,288,1,0,0,0,266,268,3,74,37,
  	0,267,269,3,46,23,0,268,267,1,0,0,0,268,269,1,0,0,0,269,271,1,0,0,0,270,
  	272,3,54,27,0,271,270,1,0,0,0,271,272,1,0,0,0,272,288,1,0,0,0,273,275,
  	3,80,40,0,274,276,3,46,23,0,275,274,1,0,0,0,275,276,1,0,0,0,276,278,1,
  	0,0,0,277,279,3,54,27,0,278,277,1,0,0,0,278,279,1,0,0,0,279,288,1,0,0,
  	0,280,282,3,82,41,0,281,283,3,46,23,0,282,281,1,0,0,0,282,283,1,0,0,0,
  	283,285,1,0,0,0,284,286,3,54,27,0,285,284,1,0,0,0,285,286,1,0,0,0,286,
  	288,1,0,0,0,287,259,1,0,0,0,287,266,1,0,0,0,287,273,1,0,0,0,287,280,1,
  	0,0,0,288,45,1,0,0,0,289,293,3,50,25,0,290,293,3,48,24,0,291,293,3,52,
  	26,0,292,289,1,0,0,0,292,290,1,0,0,0,292,291,1,0,0,0,293,47,1,0,0,0,294,
  	295,5,30,0,0,295,49,1,0,0,0,296,297,5,30,0,0,297,298,5,30,0,0,298,51,
  	1,0,0,0,299,300,5,31,0,0,300,53,1,0,0,0,301,308,3,56,28,0,302,308,3,58,
  	29,0,303,308,3,60,30,0,304,308,3,62,31,0,305,308,3,64,32,0,306,308,3,
  	66,33,0,307,301,1,0,0,0,307,302,1,0,0,0,307,303,1,0,0,0,307,304,1,0,0,
  	0,307,305,1,0,0,0,307,306,1,0,0,0,308,55,1,0,0,0,309,310,5,24,0,0,310,
  	57,1,0,0,0,311,312,5,25,0,0,312,59,1,0,0,0,313,314,5,26,0,0,314,61,1,
  	0,0,0,315,316,5,27,0,0,316,63,1,0,0,0,317,318,5,28,0,0,318,65,1,0,0,0,
  	319,320,5,29,0,0,320,67,1,0,0,0,321,324,3,70,35,0,322,324,3,72,36,0,323,
  	321,1,0,0,0,323,322,1,0,0,0,324,69,1,0,0,0,325,326,5,18,0,0,326,327,5,
  	21,0,0,327,330,5,15,0,0,328,329,5,16,0,0,329,331,3,78,39,0,330,328,1,
  	0,0,0,330,331,1,0,0,0,331,71,1,0,0,0,332,334,3,78,39,0,333,335,5,18,0,
  	0,334,333,1,0,0,0,334,335,1,0,0,0,335,337,1,0,0,0,336,338,5,17,0,0,337,
  	336,1,0,0,0,337,338,1,0,0,0,338,339,1,0,0,0,339,340,5,21,0,0,340,341,
  	5,15,0,0,341,73,1,0,0,0,342,345,5,15,0,0,343,344,5,16,0,0,344,346,3,78,
  	39,0,345,343,1,0,0,0,345,346,1,0,0,0,346,75,1,0,0,0,347,348,5,15,0,0,
  	348,349,5,16,0,0,349,350,3,78,39,0,350,77,1,0,0,0,351,352,5,14,0,0,352,
  	79,1,0,0,0,353,355,3,78,39,0,354,356,5,17,0,0,355,354,1,0,0,0,355,356,
  	1,0,0,0,356,358,1,0,0,0,357,359,5,18,0,0,358,357,1,0,0,0,358,359,1,0,
  	0,0,359,360,1,0,0,0,360,361,5,15,0,0,361,81,1,0,0,0,362,363,7,1,0,0,363,
  	83,1,0,0,0,364,365,7,2,0,0,365,366,3,86,43,0,366,367,5,40,0,0,367,85,
  	1,0,0,0,368,370,3,88,44,0,369,368,1,0,0,0,369,370,1,0,0,0,370,374,1,0,
  	0,0,371,373,3,90,45,0,372,371,1,0,0,0,373,376,1,0,0,0,374,372,1,0,0,0,
  	374,375,1,0,0,0,375,378,1,0,0,0,376,374,1,0,0,0,377,379,3,88,44,0,378,
  	377,1,0,0,0,378,379,1,0,0,0,379,87,1,0,0,0,380,381,5,41,0,0,381,89,1,
  	0,0,0,382,383,5,39,0,0,383,384,3,92,46,0,384,385,3,94,47,0,385,386,5,
  	43,0,0,386,91,1,0,0,0,387,388,5,42,0,0,388,93,1,0,0,0,389,394,5,45,0,
  	0,390,391,5,44,0,0,391,393,5,45,0,0,392,390,1,0,0,0,393,396,1,0,0,0,394,
  	392,1,0,0,0,394,395,1,0,0,0,395,95,1,0,0,0,396,394,1,0,0,0,45,100,109,
  	114,122,126,133,140,152,159,166,178,182,188,199,206,213,219,225,229,234,
  	240,246,253,261,264,268,271,275,278,282,285,287,292,307,323,330,334,337,
  	345,355,358,369,374,378,394
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  enhancedpgnparserParserStaticData = staticData.release();
}

}

EnhancedPGNParser::EnhancedPGNParser(TokenStream *input) : EnhancedPGNParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

EnhancedPGNParser::EnhancedPGNParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  EnhancedPGNParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *enhancedpgnparserParserStaticData->atn, enhancedpgnparserParserStaticData->decisionToDFA, enhancedpgnparserParserStaticData->sharedContextCache, options);
}

EnhancedPGNParser::~EnhancedPGNParser() {
  delete _interpreter;
}

const atn::ATN& EnhancedPGNParser::getATN() const {
  return *enhancedpgnparserParserStaticData->atn;
}

std::string EnhancedPGNParser::getGrammarFileName() const {
  return "EnhancedPGNParser.g4";
}

const std::vector<std::string>& EnhancedPGNParser::getRuleNames() const {
  return enhancedpgnparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& EnhancedPGNParser::getVocabulary() const {
  return enhancedpgnparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView EnhancedPGNParser::getSerializedATN() const {
  return enhancedpgnparserParserStaticData->serializedATN;
}


//----------------- ParseContext ------------------------------------------------------------------

EnhancedPGNParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Pgn_databaseContext* EnhancedPGNParser::ParseContext::pgn_database() {
  return getRuleContext<EnhancedPGNParser::Pgn_databaseContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::ParseContext::EOF() {
  return getToken(EnhancedPGNParser::EOF, 0);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::ParseContext::NEW_LINE() {
  return getTokens(EnhancedPGNParser::NEW_LINE);
}

tree::TerminalNode* EnhancedPGNParser::ParseContext::NEW_LINE(size_t i) {
  return getToken(EnhancedPGNParser::NEW_LINE, i);
}


size_t EnhancedPGNParser::ParseContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleParse;
}

void EnhancedPGNParser::ParseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParse(this);
}

void EnhancedPGNParser::ParseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParse(this);
}

EnhancedPGNParser::ParseContext* EnhancedPGNParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, EnhancedPGNParser::RuleParse);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    pgn_database();
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EnhancedPGNParser::NEW_LINE) {
      setState(97);
      match(EnhancedPGNParser::NEW_LINE);
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(103);
    match(EnhancedPGNParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pgn_databaseContext ------------------------------------------------------------------

EnhancedPGNParser::Pgn_databaseContext::Pgn_databaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EnhancedPGNParser::PgnContext *> EnhancedPGNParser::Pgn_databaseContext::pgn() {
  return getRuleContexts<EnhancedPGNParser::PgnContext>();
}

EnhancedPGNParser::PgnContext* EnhancedPGNParser::Pgn_databaseContext::pgn(size_t i) {
  return getRuleContext<EnhancedPGNParser::PgnContext>(i);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Pgn_databaseContext::NEW_LINE() {
  return getTokens(EnhancedPGNParser::NEW_LINE);
}

tree::TerminalNode* EnhancedPGNParser::Pgn_databaseContext::NEW_LINE(size_t i) {
  return getToken(EnhancedPGNParser::NEW_LINE, i);
}


size_t EnhancedPGNParser::Pgn_databaseContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePgn_database;
}

void EnhancedPGNParser::Pgn_databaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPgn_database(this);
}

void EnhancedPGNParser::Pgn_databaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPgn_database(this);
}

EnhancedPGNParser::Pgn_databaseContext* EnhancedPGNParser::pgn_database() {
  Pgn_databaseContext *_localctx = _tracker.createInstance<Pgn_databaseContext>(_ctx, getState());
  enterRule(_localctx, 2, EnhancedPGNParser::RulePgn_database);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    pgn();
    setState(114);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(107); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(106);
          match(EnhancedPGNParser::NEW_LINE);
          setState(109); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == EnhancedPGNParser::NEW_LINE);
        setState(111);
        pgn(); 
      }
      setState(116);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PgnContext ------------------------------------------------------------------

EnhancedPGNParser::PgnContext::PgnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Move_textContext* EnhancedPGNParser::PgnContext::move_text() {
  return getRuleContext<EnhancedPGNParser::Move_textContext>(0);
}

EnhancedPGNParser::Tag_pairsContext* EnhancedPGNParser::PgnContext::tag_pairs() {
  return getRuleContext<EnhancedPGNParser::Tag_pairsContext>(0);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::PgnContext::NEW_LINE() {
  return getTokens(EnhancedPGNParser::NEW_LINE);
}

tree::TerminalNode* EnhancedPGNParser::PgnContext::NEW_LINE(size_t i) {
  return getToken(EnhancedPGNParser::NEW_LINE, i);
}


size_t EnhancedPGNParser::PgnContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePgn;
}

void EnhancedPGNParser::PgnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPgn(this);
}

void EnhancedPGNParser::PgnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPgn(this);
}

EnhancedPGNParser::PgnContext* EnhancedPGNParser::pgn() {
  PgnContext *_localctx = _tracker.createInstance<PgnContext>(_ctx, getState());
  enterRule(_localctx, 4, EnhancedPGNParser::RulePgn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::MOVE_TEXT_START:
      case EnhancedPGNParser::MOVE_TEXT_START_WITH_COMMENT:
      case EnhancedPGNParser::EOL_COMMENT_START:
      case EnhancedPGNParser::MOVE_NUM:
      case EnhancedPGNParser::BLOCK_COMMENT_START:
      case EnhancedPGNParser::WHITE_WINS:
      case EnhancedPGNParser::BLACK_WINS:
      case EnhancedPGNParser::DRAW:
      case EnhancedPGNParser::UNKOWN_ENDING:
      case EnhancedPGNParser::NAG: {
        enterOuterAlt(_localctx, 1);
        setState(117);
        move_text();
        break;
      }

      case EnhancedPGNParser::TAG_START: {
        enterOuterAlt(_localctx, 2);
        setState(118);
        tag_pairs();
        setState(120); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(119);
          match(EnhancedPGNParser::NEW_LINE);
          setState(122); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == EnhancedPGNParser::NEW_LINE);
        setState(124);
        move_text();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tag_pairsContext ------------------------------------------------------------------

EnhancedPGNParser::Tag_pairsContext::Tag_pairsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EnhancedPGNParser::Tag_pairContext *> EnhancedPGNParser::Tag_pairsContext::tag_pair() {
  return getRuleContexts<EnhancedPGNParser::Tag_pairContext>();
}

EnhancedPGNParser::Tag_pairContext* EnhancedPGNParser::Tag_pairsContext::tag_pair(size_t i) {
  return getRuleContext<EnhancedPGNParser::Tag_pairContext>(i);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Tag_pairsContext::NEW_LINE() {
  return getTokens(EnhancedPGNParser::NEW_LINE);
}

tree::TerminalNode* EnhancedPGNParser::Tag_pairsContext::NEW_LINE(size_t i) {
  return getToken(EnhancedPGNParser::NEW_LINE, i);
}


size_t EnhancedPGNParser::Tag_pairsContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTag_pairs;
}

void EnhancedPGNParser::Tag_pairsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag_pairs(this);
}

void EnhancedPGNParser::Tag_pairsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag_pairs(this);
}

EnhancedPGNParser::Tag_pairsContext* EnhancedPGNParser::tag_pairs() {
  Tag_pairsContext *_localctx = _tracker.createInstance<Tag_pairsContext>(_ctx, getState());
  enterRule(_localctx, 6, EnhancedPGNParser::RuleTag_pairs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(128);
      tag_pair();
      setState(129);
      match(EnhancedPGNParser::NEW_LINE);
      setState(133); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == EnhancedPGNParser::TAG_START);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tag_pairContext ------------------------------------------------------------------

EnhancedPGNParser::Tag_pairContext::Tag_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Tag_pairContext::TAG_START() {
  return getToken(EnhancedPGNParser::TAG_START, 0);
}

EnhancedPGNParser::Tag_keyContext* EnhancedPGNParser::Tag_pairContext::tag_key() {
  return getRuleContext<EnhancedPGNParser::Tag_keyContext>(0);
}

EnhancedPGNParser::Tag_valueContext* EnhancedPGNParser::Tag_pairContext::tag_value() {
  return getRuleContext<EnhancedPGNParser::Tag_valueContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::Tag_pairContext::TAG_END() {
  return getToken(EnhancedPGNParser::TAG_END, 0);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Tag_pairContext::TAG_SPACE() {
  return getTokens(EnhancedPGNParser::TAG_SPACE);
}

tree::TerminalNode* EnhancedPGNParser::Tag_pairContext::TAG_SPACE(size_t i) {
  return getToken(EnhancedPGNParser::TAG_SPACE, i);
}


size_t EnhancedPGNParser::Tag_pairContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTag_pair;
}

void EnhancedPGNParser::Tag_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag_pair(this);
}

void EnhancedPGNParser::Tag_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag_pair(this);
}

EnhancedPGNParser::Tag_pairContext* EnhancedPGNParser::tag_pair() {
  Tag_pairContext *_localctx = _tracker.createInstance<Tag_pairContext>(_ctx, getState());
  enterRule(_localctx, 8, EnhancedPGNParser::RuleTag_pair);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(EnhancedPGNParser::TAG_START);
    setState(136);
    tag_key();
    setState(138); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(137);
      match(EnhancedPGNParser::TAG_SPACE);
      setState(140); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == EnhancedPGNParser::TAG_SPACE);
    setState(142);
    tag_value();
    setState(143);
    match(EnhancedPGNParser::TAG_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tag_keyContext ------------------------------------------------------------------

EnhancedPGNParser::Tag_keyContext::Tag_keyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Tag_keyContext::TAG_KEY() {
  return getToken(EnhancedPGNParser::TAG_KEY, 0);
}


size_t EnhancedPGNParser::Tag_keyContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTag_key;
}

void EnhancedPGNParser::Tag_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag_key(this);
}

void EnhancedPGNParser::Tag_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag_key(this);
}

EnhancedPGNParser::Tag_keyContext* EnhancedPGNParser::tag_key() {
  Tag_keyContext *_localctx = _tracker.createInstance<Tag_keyContext>(_ctx, getState());
  enterRule(_localctx, 10, EnhancedPGNParser::RuleTag_key);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(EnhancedPGNParser::TAG_KEY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tag_valueContext ------------------------------------------------------------------

EnhancedPGNParser::Tag_valueContext::Tag_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Tag_valueContext::TAG_VALUE() {
  return getToken(EnhancedPGNParser::TAG_VALUE, 0);
}


size_t EnhancedPGNParser::Tag_valueContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTag_value;
}

void EnhancedPGNParser::Tag_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag_value(this);
}

void EnhancedPGNParser::Tag_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag_value(this);
}

EnhancedPGNParser::Tag_valueContext* EnhancedPGNParser::tag_value() {
  Tag_valueContext *_localctx = _tracker.createInstance<Tag_valueContext>(_ctx, getState());
  enterRule(_localctx, 12, EnhancedPGNParser::RuleTag_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(EnhancedPGNParser::TAG_VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Move_textContext ------------------------------------------------------------------

EnhancedPGNParser::Move_textContext::Move_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Game_terminationContext* EnhancedPGNParser::Move_textContext::game_termination() {
  return getRuleContext<EnhancedPGNParser::Game_terminationContext>(0);
}

std::vector<EnhancedPGNParser::Move_text_itemContext *> EnhancedPGNParser::Move_textContext::move_text_item() {
  return getRuleContexts<EnhancedPGNParser::Move_text_itemContext>();
}

EnhancedPGNParser::Move_text_itemContext* EnhancedPGNParser::Move_textContext::move_text_item(size_t i) {
  return getRuleContext<EnhancedPGNParser::Move_text_itemContext>(i);
}

std::vector<EnhancedPGNParser::CommentContext *> EnhancedPGNParser::Move_textContext::comment() {
  return getRuleContexts<EnhancedPGNParser::CommentContext>();
}

EnhancedPGNParser::CommentContext* EnhancedPGNParser::Move_textContext::comment(size_t i) {
  return getRuleContext<EnhancedPGNParser::CommentContext>(i);
}


size_t EnhancedPGNParser::Move_textContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleMove_text;
}

void EnhancedPGNParser::Move_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMove_text(this);
}

void EnhancedPGNParser::Move_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMove_text(this);
}

EnhancedPGNParser::Move_textContext* EnhancedPGNParser::move_text() {
  Move_textContext *_localctx = _tracker.createInstance<Move_textContext>(_ctx, getState());
  enterRule(_localctx, 14, EnhancedPGNParser::RuleMove_text);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68719483928) != 0)) {
      setState(149);
      move_text_item();
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(155);
    game_termination();
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5136) != 0)) {
      setState(156);
      comment();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Game_terminationContext ------------------------------------------------------------------

EnhancedPGNParser::Game_terminationContext::Game_terminationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::White_winsContext* EnhancedPGNParser::Game_terminationContext::white_wins() {
  return getRuleContext<EnhancedPGNParser::White_winsContext>(0);
}

EnhancedPGNParser::Black_winsContext* EnhancedPGNParser::Game_terminationContext::black_wins() {
  return getRuleContext<EnhancedPGNParser::Black_winsContext>(0);
}

EnhancedPGNParser::DrawContext* EnhancedPGNParser::Game_terminationContext::draw() {
  return getRuleContext<EnhancedPGNParser::DrawContext>(0);
}

EnhancedPGNParser::Unknown_endingContext* EnhancedPGNParser::Game_terminationContext::unknown_ending() {
  return getRuleContext<EnhancedPGNParser::Unknown_endingContext>(0);
}


size_t EnhancedPGNParser::Game_terminationContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleGame_termination;
}

void EnhancedPGNParser::Game_terminationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGame_termination(this);
}

void EnhancedPGNParser::Game_terminationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGame_termination(this);
}

EnhancedPGNParser::Game_terminationContext* EnhancedPGNParser::game_termination() {
  Game_terminationContext *_localctx = _tracker.createInstance<Game_terminationContext>(_ctx, getState());
  enterRule(_localctx, 16, EnhancedPGNParser::RuleGame_termination);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(166);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::WHITE_WINS: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        white_wins();
        break;
      }

      case EnhancedPGNParser::BLACK_WINS: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        black_wins();
        break;
      }

      case EnhancedPGNParser::DRAW: {
        enterOuterAlt(_localctx, 3);
        setState(164);
        draw();
        break;
      }

      case EnhancedPGNParser::UNKOWN_ENDING: {
        enterOuterAlt(_localctx, 4);
        setState(165);
        unknown_ending();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- White_winsContext ------------------------------------------------------------------

EnhancedPGNParser::White_winsContext::White_winsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::White_winsContext::WHITE_WINS() {
  return getToken(EnhancedPGNParser::WHITE_WINS, 0);
}


size_t EnhancedPGNParser::White_winsContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleWhite_wins;
}

void EnhancedPGNParser::White_winsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhite_wins(this);
}

void EnhancedPGNParser::White_winsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhite_wins(this);
}

EnhancedPGNParser::White_winsContext* EnhancedPGNParser::white_wins() {
  White_winsContext *_localctx = _tracker.createInstance<White_winsContext>(_ctx, getState());
  enterRule(_localctx, 18, EnhancedPGNParser::RuleWhite_wins);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(EnhancedPGNParser::WHITE_WINS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Black_winsContext ------------------------------------------------------------------

EnhancedPGNParser::Black_winsContext::Black_winsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Black_winsContext::BLACK_WINS() {
  return getToken(EnhancedPGNParser::BLACK_WINS, 0);
}


size_t EnhancedPGNParser::Black_winsContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBlack_wins;
}

void EnhancedPGNParser::Black_winsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlack_wins(this);
}

void EnhancedPGNParser::Black_winsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlack_wins(this);
}

EnhancedPGNParser::Black_winsContext* EnhancedPGNParser::black_wins() {
  Black_winsContext *_localctx = _tracker.createInstance<Black_winsContext>(_ctx, getState());
  enterRule(_localctx, 20, EnhancedPGNParser::RuleBlack_wins);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(EnhancedPGNParser::BLACK_WINS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DrawContext ------------------------------------------------------------------

EnhancedPGNParser::DrawContext::DrawContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::DrawContext::DRAW() {
  return getToken(EnhancedPGNParser::DRAW, 0);
}


size_t EnhancedPGNParser::DrawContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleDraw;
}

void EnhancedPGNParser::DrawContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDraw(this);
}

void EnhancedPGNParser::DrawContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDraw(this);
}

EnhancedPGNParser::DrawContext* EnhancedPGNParser::draw() {
  DrawContext *_localctx = _tracker.createInstance<DrawContext>(_ctx, getState());
  enterRule(_localctx, 22, EnhancedPGNParser::RuleDraw);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(EnhancedPGNParser::DRAW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unknown_endingContext ------------------------------------------------------------------

EnhancedPGNParser::Unknown_endingContext::Unknown_endingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Unknown_endingContext::UNKOWN_ENDING() {
  return getToken(EnhancedPGNParser::UNKOWN_ENDING, 0);
}


size_t EnhancedPGNParser::Unknown_endingContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleUnknown_ending;
}

void EnhancedPGNParser::Unknown_endingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnknown_ending(this);
}

void EnhancedPGNParser::Unknown_endingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnknown_ending(this);
}

EnhancedPGNParser::Unknown_endingContext* EnhancedPGNParser::unknown_ending() {
  Unknown_endingContext *_localctx = _tracker.createInstance<Unknown_endingContext>(_ctx, getState());
  enterRule(_localctx, 24, EnhancedPGNParser::RuleUnknown_ending);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(EnhancedPGNParser::UNKOWN_ENDING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Move_text_itemContext ------------------------------------------------------------------

EnhancedPGNParser::Move_text_itemContext::Move_text_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::TurnContext* EnhancedPGNParser::Move_text_itemContext::turn() {
  return getRuleContext<EnhancedPGNParser::TurnContext>(0);
}

EnhancedPGNParser::CommentContext* EnhancedPGNParser::Move_text_itemContext::comment() {
  return getRuleContext<EnhancedPGNParser::CommentContext>(0);
}


size_t EnhancedPGNParser::Move_text_itemContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleMove_text_item;
}

void EnhancedPGNParser::Move_text_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMove_text_item(this);
}

void EnhancedPGNParser::Move_text_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMove_text_item(this);
}

EnhancedPGNParser::Move_text_itemContext* EnhancedPGNParser::move_text_item() {
  Move_text_itemContext *_localctx = _tracker.createInstance<Move_text_itemContext>(_ctx, getState());
  enterRule(_localctx, 26, EnhancedPGNParser::RuleMove_text_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      turn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      comment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Turn_itemContext ------------------------------------------------------------------

EnhancedPGNParser::Turn_itemContext::Turn_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::NagContext* EnhancedPGNParser::Turn_itemContext::nag() {
  return getRuleContext<EnhancedPGNParser::NagContext>(0);
}

EnhancedPGNParser::CommentContext* EnhancedPGNParser::Turn_itemContext::comment() {
  return getRuleContext<EnhancedPGNParser::CommentContext>(0);
}


size_t EnhancedPGNParser::Turn_itemContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTurn_item;
}

void EnhancedPGNParser::Turn_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTurn_item(this);
}

void EnhancedPGNParser::Turn_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTurn_item(this);
}

EnhancedPGNParser::Turn_itemContext* EnhancedPGNParser::turn_item() {
  Turn_itemContext *_localctx = _tracker.createInstance<Turn_itemContext>(_ctx, getState());
  enterRule(_localctx, 28, EnhancedPGNParser::RuleTurn_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::NAG: {
        enterOuterAlt(_localctx, 1);
        setState(180);
        nag();
        break;
      }

      case EnhancedPGNParser::MOVE_TEXT_START_WITH_COMMENT:
      case EnhancedPGNParser::EOL_COMMENT_START:
      case EnhancedPGNParser::BLOCK_COMMENT_START: {
        enterOuterAlt(_localctx, 2);
        setState(181);
        comment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NagContext ------------------------------------------------------------------

EnhancedPGNParser::NagContext::NagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::NagContext::NAG() {
  return getToken(EnhancedPGNParser::NAG, 0);
}


size_t EnhancedPGNParser::NagContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleNag;
}

void EnhancedPGNParser::NagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNag(this);
}

void EnhancedPGNParser::NagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNag(this);
}

EnhancedPGNParser::NagContext* EnhancedPGNParser::nag() {
  NagContext *_localctx = _tracker.createInstance<NagContext>(_ctx, getState());
  enterRule(_localctx, 30, EnhancedPGNParser::RuleNag);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(EnhancedPGNParser::NAG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

EnhancedPGNParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Block_commentContext* EnhancedPGNParser::CommentContext::block_comment() {
  return getRuleContext<EnhancedPGNParser::Block_commentContext>(0);
}

EnhancedPGNParser::Eol_commentContext* EnhancedPGNParser::CommentContext::eol_comment() {
  return getRuleContext<EnhancedPGNParser::Eol_commentContext>(0);
}


size_t EnhancedPGNParser::CommentContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleComment;
}

void EnhancedPGNParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void EnhancedPGNParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}

EnhancedPGNParser::CommentContext* EnhancedPGNParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 32, EnhancedPGNParser::RuleComment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::MOVE_TEXT_START_WITH_COMMENT:
      case EnhancedPGNParser::BLOCK_COMMENT_START: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        block_comment();
        break;
      }

      case EnhancedPGNParser::EOL_COMMENT_START: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        eol_comment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Eol_commentContext ------------------------------------------------------------------

EnhancedPGNParser::Eol_commentContext::Eol_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Eol_commentContext::EOL_COMMENT_START() {
  return getToken(EnhancedPGNParser::EOL_COMMENT_START, 0);
}

EnhancedPGNParser::Eol_comment_bodyContext* EnhancedPGNParser::Eol_commentContext::eol_comment_body() {
  return getRuleContext<EnhancedPGNParser::Eol_comment_bodyContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::Eol_commentContext::EOL_COMMENT_END() {
  return getToken(EnhancedPGNParser::EOL_COMMENT_END, 0);
}


size_t EnhancedPGNParser::Eol_commentContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleEol_comment;
}

void EnhancedPGNParser::Eol_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEol_comment(this);
}

void EnhancedPGNParser::Eol_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEol_comment(this);
}

EnhancedPGNParser::Eol_commentContext* EnhancedPGNParser::eol_comment() {
  Eol_commentContext *_localctx = _tracker.createInstance<Eol_commentContext>(_ctx, getState());
  enterRule(_localctx, 34, EnhancedPGNParser::RuleEol_comment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(EnhancedPGNParser::EOL_COMMENT_START);
    setState(191);
    eol_comment_body();
    setState(192);
    match(EnhancedPGNParser::EOL_COMMENT_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Eol_comment_bodyContext ------------------------------------------------------------------

EnhancedPGNParser::Eol_comment_bodyContext::Eol_comment_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Eol_comment_bodyContext::EOL_COMMENT_TEXT() {
  return getToken(EnhancedPGNParser::EOL_COMMENT_TEXT, 0);
}


size_t EnhancedPGNParser::Eol_comment_bodyContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleEol_comment_body;
}

void EnhancedPGNParser::Eol_comment_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEol_comment_body(this);
}

void EnhancedPGNParser::Eol_comment_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEol_comment_body(this);
}

EnhancedPGNParser::Eol_comment_bodyContext* EnhancedPGNParser::eol_comment_body() {
  Eol_comment_bodyContext *_localctx = _tracker.createInstance<Eol_comment_bodyContext>(_ctx, getState());
  enterRule(_localctx, 36, EnhancedPGNParser::RuleEol_comment_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(EnhancedPGNParser::EOL_COMMENT_TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TurnContext ------------------------------------------------------------------

EnhancedPGNParser::TurnContext::TurnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Move_numContext* EnhancedPGNParser::TurnContext::move_num() {
  return getRuleContext<EnhancedPGNParser::Move_numContext>(0);
}

std::vector<EnhancedPGNParser::SanContext *> EnhancedPGNParser::TurnContext::san() {
  return getRuleContexts<EnhancedPGNParser::SanContext>();
}

EnhancedPGNParser::SanContext* EnhancedPGNParser::TurnContext::san(size_t i) {
  return getRuleContext<EnhancedPGNParser::SanContext>(i);
}

std::vector<EnhancedPGNParser::Turn_itemContext *> EnhancedPGNParser::TurnContext::turn_item() {
  return getRuleContexts<EnhancedPGNParser::Turn_itemContext>();
}

EnhancedPGNParser::Turn_itemContext* EnhancedPGNParser::TurnContext::turn_item(size_t i) {
  return getRuleContext<EnhancedPGNParser::Turn_itemContext>(i);
}

std::vector<EnhancedPGNParser::Alternate_lineContext *> EnhancedPGNParser::TurnContext::alternate_line() {
  return getRuleContexts<EnhancedPGNParser::Alternate_lineContext>();
}

EnhancedPGNParser::Alternate_lineContext* EnhancedPGNParser::TurnContext::alternate_line(size_t i) {
  return getRuleContext<EnhancedPGNParser::Alternate_lineContext>(i);
}


size_t EnhancedPGNParser::TurnContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleTurn;
}

void EnhancedPGNParser::TurnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTurn(this);
}

void EnhancedPGNParser::TurnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTurn(this);
}

EnhancedPGNParser::TurnContext* EnhancedPGNParser::turn() {
  TurnContext *_localctx = _tracker.createInstance<TurnContext>(_ctx, getState());
  enterRule(_localctx, 38, EnhancedPGNParser::RuleTurn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68719481872) != 0)) {
      setState(196);
      turn_item();
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    move_num();
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68719481872) != 0)) {
      setState(203);
      turn_item();
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(209);
    san(0);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(210);
        turn_item(); 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(216);
        alternate_line(0); 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(225);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(222);
        turn_item(); 
      }
      setState(227);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1884160) != 0)) {
      setState(228);
      san(1);
    }
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(231);
        turn_item(); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(240);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EnhancedPGNParser::ALTERNATE_LINE_START) {
      setState(237);
      alternate_line(1);
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(243);
        turn_item(); 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alternate_lineContext ------------------------------------------------------------------

EnhancedPGNParser::Alternate_lineContext::Alternate_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Alternate_lineContext::Alternate_lineContext(ParserRuleContext *parent, size_t invokingState, int number)
  : ParserRuleContext(parent, invokingState) {
  this->number = number;
}

tree::TerminalNode* EnhancedPGNParser::Alternate_lineContext::ALTERNATE_LINE_START() {
  return getToken(EnhancedPGNParser::ALTERNATE_LINE_START, 0);
}

tree::TerminalNode* EnhancedPGNParser::Alternate_lineContext::ALTERNATE_LINE_END() {
  return getToken(EnhancedPGNParser::ALTERNATE_LINE_END, 0);
}

std::vector<EnhancedPGNParser::TurnContext *> EnhancedPGNParser::Alternate_lineContext::turn() {
  return getRuleContexts<EnhancedPGNParser::TurnContext>();
}

EnhancedPGNParser::TurnContext* EnhancedPGNParser::Alternate_lineContext::turn(size_t i) {
  return getRuleContext<EnhancedPGNParser::TurnContext>(i);
}


size_t EnhancedPGNParser::Alternate_lineContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleAlternate_line;
}

void EnhancedPGNParser::Alternate_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlternate_line(this);
}

void EnhancedPGNParser::Alternate_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlternate_line(this);
}

EnhancedPGNParser::Alternate_lineContext* EnhancedPGNParser::alternate_line(int number) {
  Alternate_lineContext *_localctx = _tracker.createInstance<Alternate_lineContext>(_ctx, getState(), number);
  enterRule(_localctx, 40, EnhancedPGNParser::RuleAlternate_line);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(EnhancedPGNParser::ALTERNATE_LINE_START);
    setState(251); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(250);
      turn();
      setState(253); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68719483928) != 0));
    setState(255);
    match(EnhancedPGNParser::ALTERNATE_LINE_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Move_numContext ------------------------------------------------------------------

EnhancedPGNParser::Move_numContext::Move_numContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Move_numContext::MOVE_TEXT_START() {
  return getToken(EnhancedPGNParser::MOVE_TEXT_START, 0);
}

tree::TerminalNode* EnhancedPGNParser::Move_numContext::MOVE_NUM() {
  return getToken(EnhancedPGNParser::MOVE_NUM, 0);
}


size_t EnhancedPGNParser::Move_numContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleMove_num;
}

void EnhancedPGNParser::Move_numContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMove_num(this);
}

void EnhancedPGNParser::Move_numContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMove_num(this);
}

EnhancedPGNParser::Move_numContext* EnhancedPGNParser::move_num() {
  Move_numContext *_localctx = _tracker.createInstance<Move_numContext>(_ctx, getState());
  enterRule(_localctx, 42, EnhancedPGNParser::RuleMove_num);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == EnhancedPGNParser::MOVE_TEXT_START

    || _la == EnhancedPGNParser::MOVE_NUM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SanContext ------------------------------------------------------------------

EnhancedPGNParser::SanContext::SanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::SanContext::SanContext(ParserRuleContext *parent, size_t invokingState, int number)
  : ParserRuleContext(parent, invokingState) {
  this->number = number;
}

EnhancedPGNParser::CaptureContext* EnhancedPGNParser::SanContext::capture() {
  return getRuleContext<EnhancedPGNParser::CaptureContext>(0);
}

EnhancedPGNParser::Check_likeContext* EnhancedPGNParser::SanContext::check_like() {
  return getRuleContext<EnhancedPGNParser::Check_likeContext>(0);
}

EnhancedPGNParser::Move_analysisContext* EnhancedPGNParser::SanContext::move_analysis() {
  return getRuleContext<EnhancedPGNParser::Move_analysisContext>(0);
}

EnhancedPGNParser::Pawn_moveContext* EnhancedPGNParser::SanContext::pawn_move() {
  return getRuleContext<EnhancedPGNParser::Pawn_moveContext>(0);
}

EnhancedPGNParser::Piece_moveContext* EnhancedPGNParser::SanContext::piece_move() {
  return getRuleContext<EnhancedPGNParser::Piece_moveContext>(0);
}

EnhancedPGNParser::CastleContext* EnhancedPGNParser::SanContext::castle() {
  return getRuleContext<EnhancedPGNParser::CastleContext>(0);
}


size_t EnhancedPGNParser::SanContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleSan;
}

void EnhancedPGNParser::SanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSan(this);
}

void EnhancedPGNParser::SanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSan(this);
}

EnhancedPGNParser::SanContext* EnhancedPGNParser::san(int number) {
  SanContext *_localctx = _tracker.createInstance<SanContext>(_ctx, getState(), number);
  enterRule(_localctx, 44, EnhancedPGNParser::RuleSan);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(259);
      capture();
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == EnhancedPGNParser::CHECK

      || _la == EnhancedPGNParser::CHECKMATE) {
        setState(260);
        check_like();
      }
      setState(264);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1056964608) != 0)) {
        setState(263);
        move_analysis();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(266);
      pawn_move();
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == EnhancedPGNParser::CHECK

      || _la == EnhancedPGNParser::CHECKMATE) {
        setState(267);
        check_like();
      }
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1056964608) != 0)) {
        setState(270);
        move_analysis();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(273);
      piece_move();
      setState(275);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == EnhancedPGNParser::CHECK

      || _la == EnhancedPGNParser::CHECKMATE) {
        setState(274);
        check_like();
      }
      setState(278);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1056964608) != 0)) {
        setState(277);
        move_analysis();
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(280);
      castle();
      setState(282);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == EnhancedPGNParser::CHECK

      || _la == EnhancedPGNParser::CHECKMATE) {
        setState(281);
        check_like();
      }
      setState(285);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1056964608) != 0)) {
        setState(284);
        move_analysis();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Check_likeContext ------------------------------------------------------------------

EnhancedPGNParser::Check_likeContext::Check_likeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Double_checkContext* EnhancedPGNParser::Check_likeContext::double_check() {
  return getRuleContext<EnhancedPGNParser::Double_checkContext>(0);
}

EnhancedPGNParser::CheckContext* EnhancedPGNParser::Check_likeContext::check() {
  return getRuleContext<EnhancedPGNParser::CheckContext>(0);
}

EnhancedPGNParser::CheckmateContext* EnhancedPGNParser::Check_likeContext::checkmate() {
  return getRuleContext<EnhancedPGNParser::CheckmateContext>(0);
}


size_t EnhancedPGNParser::Check_likeContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCheck_like;
}

void EnhancedPGNParser::Check_likeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheck_like(this);
}

void EnhancedPGNParser::Check_likeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheck_like(this);
}

EnhancedPGNParser::Check_likeContext* EnhancedPGNParser::check_like() {
  Check_likeContext *_localctx = _tracker.createInstance<Check_likeContext>(_ctx, getState());
  enterRule(_localctx, 46, EnhancedPGNParser::RuleCheck_like);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(292);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(289);
      double_check();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(290);
      check();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(291);
      checkmate();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckContext ------------------------------------------------------------------

EnhancedPGNParser::CheckContext::CheckContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::CheckContext::CHECK() {
  return getToken(EnhancedPGNParser::CHECK, 0);
}


size_t EnhancedPGNParser::CheckContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCheck;
}

void EnhancedPGNParser::CheckContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheck(this);
}

void EnhancedPGNParser::CheckContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheck(this);
}

EnhancedPGNParser::CheckContext* EnhancedPGNParser::check() {
  CheckContext *_localctx = _tracker.createInstance<CheckContext>(_ctx, getState());
  enterRule(_localctx, 48, EnhancedPGNParser::RuleCheck);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(EnhancedPGNParser::CHECK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Double_checkContext ------------------------------------------------------------------

EnhancedPGNParser::Double_checkContext::Double_checkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Double_checkContext::CHECK() {
  return getTokens(EnhancedPGNParser::CHECK);
}

tree::TerminalNode* EnhancedPGNParser::Double_checkContext::CHECK(size_t i) {
  return getToken(EnhancedPGNParser::CHECK, i);
}


size_t EnhancedPGNParser::Double_checkContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleDouble_check;
}

void EnhancedPGNParser::Double_checkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDouble_check(this);
}

void EnhancedPGNParser::Double_checkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDouble_check(this);
}

EnhancedPGNParser::Double_checkContext* EnhancedPGNParser::double_check() {
  Double_checkContext *_localctx = _tracker.createInstance<Double_checkContext>(_ctx, getState());
  enterRule(_localctx, 50, EnhancedPGNParser::RuleDouble_check);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(EnhancedPGNParser::CHECK);
    setState(297);
    match(EnhancedPGNParser::CHECK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckmateContext ------------------------------------------------------------------

EnhancedPGNParser::CheckmateContext::CheckmateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::CheckmateContext::CHECKMATE() {
  return getToken(EnhancedPGNParser::CHECKMATE, 0);
}


size_t EnhancedPGNParser::CheckmateContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCheckmate;
}

void EnhancedPGNParser::CheckmateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckmate(this);
}

void EnhancedPGNParser::CheckmateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckmate(this);
}

EnhancedPGNParser::CheckmateContext* EnhancedPGNParser::checkmate() {
  CheckmateContext *_localctx = _tracker.createInstance<CheckmateContext>(_ctx, getState());
  enterRule(_localctx, 52, EnhancedPGNParser::RuleCheckmate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(EnhancedPGNParser::CHECKMATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Move_analysisContext ------------------------------------------------------------------

EnhancedPGNParser::Move_analysisContext::Move_analysisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::BlunderContext* EnhancedPGNParser::Move_analysisContext::blunder() {
  return getRuleContext<EnhancedPGNParser::BlunderContext>(0);
}

EnhancedPGNParser::MistakeContext* EnhancedPGNParser::Move_analysisContext::mistake() {
  return getRuleContext<EnhancedPGNParser::MistakeContext>(0);
}

EnhancedPGNParser::Dubious_moveContext* EnhancedPGNParser::Move_analysisContext::dubious_move() {
  return getRuleContext<EnhancedPGNParser::Dubious_moveContext>(0);
}

EnhancedPGNParser::Interesting_moveContext* EnhancedPGNParser::Move_analysisContext::interesting_move() {
  return getRuleContext<EnhancedPGNParser::Interesting_moveContext>(0);
}

EnhancedPGNParser::Good_moveContext* EnhancedPGNParser::Move_analysisContext::good_move() {
  return getRuleContext<EnhancedPGNParser::Good_moveContext>(0);
}

EnhancedPGNParser::Brilliant_moveContext* EnhancedPGNParser::Move_analysisContext::brilliant_move() {
  return getRuleContext<EnhancedPGNParser::Brilliant_moveContext>(0);
}


size_t EnhancedPGNParser::Move_analysisContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleMove_analysis;
}

void EnhancedPGNParser::Move_analysisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMove_analysis(this);
}

void EnhancedPGNParser::Move_analysisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMove_analysis(this);
}

EnhancedPGNParser::Move_analysisContext* EnhancedPGNParser::move_analysis() {
  Move_analysisContext *_localctx = _tracker.createInstance<Move_analysisContext>(_ctx, getState());
  enterRule(_localctx, 54, EnhancedPGNParser::RuleMove_analysis);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::BLUNDER: {
        enterOuterAlt(_localctx, 1);
        setState(301);
        blunder();
        break;
      }

      case EnhancedPGNParser::MISTAKE: {
        enterOuterAlt(_localctx, 2);
        setState(302);
        mistake();
        break;
      }

      case EnhancedPGNParser::DUBIOUS_MOVE: {
        enterOuterAlt(_localctx, 3);
        setState(303);
        dubious_move();
        break;
      }

      case EnhancedPGNParser::INTERESTING_MOVE: {
        enterOuterAlt(_localctx, 4);
        setState(304);
        interesting_move();
        break;
      }

      case EnhancedPGNParser::GOOD_MOVE: {
        enterOuterAlt(_localctx, 5);
        setState(305);
        good_move();
        break;
      }

      case EnhancedPGNParser::BRILLIANT_MOVE: {
        enterOuterAlt(_localctx, 6);
        setState(306);
        brilliant_move();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlunderContext ------------------------------------------------------------------

EnhancedPGNParser::BlunderContext::BlunderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::BlunderContext::BLUNDER() {
  return getToken(EnhancedPGNParser::BLUNDER, 0);
}


size_t EnhancedPGNParser::BlunderContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBlunder;
}

void EnhancedPGNParser::BlunderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlunder(this);
}

void EnhancedPGNParser::BlunderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlunder(this);
}

EnhancedPGNParser::BlunderContext* EnhancedPGNParser::blunder() {
  BlunderContext *_localctx = _tracker.createInstance<BlunderContext>(_ctx, getState());
  enterRule(_localctx, 56, EnhancedPGNParser::RuleBlunder);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(EnhancedPGNParser::BLUNDER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MistakeContext ------------------------------------------------------------------

EnhancedPGNParser::MistakeContext::MistakeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::MistakeContext::MISTAKE() {
  return getToken(EnhancedPGNParser::MISTAKE, 0);
}


size_t EnhancedPGNParser::MistakeContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleMistake;
}

void EnhancedPGNParser::MistakeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMistake(this);
}

void EnhancedPGNParser::MistakeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMistake(this);
}

EnhancedPGNParser::MistakeContext* EnhancedPGNParser::mistake() {
  MistakeContext *_localctx = _tracker.createInstance<MistakeContext>(_ctx, getState());
  enterRule(_localctx, 58, EnhancedPGNParser::RuleMistake);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    match(EnhancedPGNParser::MISTAKE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dubious_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Dubious_moveContext::Dubious_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Dubious_moveContext::DUBIOUS_MOVE() {
  return getToken(EnhancedPGNParser::DUBIOUS_MOVE, 0);
}


size_t EnhancedPGNParser::Dubious_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleDubious_move;
}

void EnhancedPGNParser::Dubious_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDubious_move(this);
}

void EnhancedPGNParser::Dubious_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDubious_move(this);
}

EnhancedPGNParser::Dubious_moveContext* EnhancedPGNParser::dubious_move() {
  Dubious_moveContext *_localctx = _tracker.createInstance<Dubious_moveContext>(_ctx, getState());
  enterRule(_localctx, 60, EnhancedPGNParser::RuleDubious_move);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    match(EnhancedPGNParser::DUBIOUS_MOVE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interesting_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Interesting_moveContext::Interesting_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Interesting_moveContext::INTERESTING_MOVE() {
  return getToken(EnhancedPGNParser::INTERESTING_MOVE, 0);
}


size_t EnhancedPGNParser::Interesting_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleInteresting_move;
}

void EnhancedPGNParser::Interesting_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteresting_move(this);
}

void EnhancedPGNParser::Interesting_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteresting_move(this);
}

EnhancedPGNParser::Interesting_moveContext* EnhancedPGNParser::interesting_move() {
  Interesting_moveContext *_localctx = _tracker.createInstance<Interesting_moveContext>(_ctx, getState());
  enterRule(_localctx, 62, EnhancedPGNParser::RuleInteresting_move);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(EnhancedPGNParser::INTERESTING_MOVE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Good_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Good_moveContext::Good_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Good_moveContext::GOOD_MOVE() {
  return getToken(EnhancedPGNParser::GOOD_MOVE, 0);
}


size_t EnhancedPGNParser::Good_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleGood_move;
}

void EnhancedPGNParser::Good_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGood_move(this);
}

void EnhancedPGNParser::Good_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGood_move(this);
}

EnhancedPGNParser::Good_moveContext* EnhancedPGNParser::good_move() {
  Good_moveContext *_localctx = _tracker.createInstance<Good_moveContext>(_ctx, getState());
  enterRule(_localctx, 64, EnhancedPGNParser::RuleGood_move);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(EnhancedPGNParser::GOOD_MOVE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Brilliant_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Brilliant_moveContext::Brilliant_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Brilliant_moveContext::BRILLIANT_MOVE() {
  return getToken(EnhancedPGNParser::BRILLIANT_MOVE, 0);
}


size_t EnhancedPGNParser::Brilliant_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBrilliant_move;
}

void EnhancedPGNParser::Brilliant_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrilliant_move(this);
}

void EnhancedPGNParser::Brilliant_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrilliant_move(this);
}

EnhancedPGNParser::Brilliant_moveContext* EnhancedPGNParser::brilliant_move() {
  Brilliant_moveContext *_localctx = _tracker.createInstance<Brilliant_moveContext>(_ctx, getState());
  enterRule(_localctx, 66, EnhancedPGNParser::RuleBrilliant_move);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(EnhancedPGNParser::BRILLIANT_MOVE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaptureContext ------------------------------------------------------------------

EnhancedPGNParser::CaptureContext::CaptureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Pawn_captureContext* EnhancedPGNParser::CaptureContext::pawn_capture() {
  return getRuleContext<EnhancedPGNParser::Pawn_captureContext>(0);
}

EnhancedPGNParser::Piece_captureContext* EnhancedPGNParser::CaptureContext::piece_capture() {
  return getRuleContext<EnhancedPGNParser::Piece_captureContext>(0);
}


size_t EnhancedPGNParser::CaptureContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCapture;
}

void EnhancedPGNParser::CaptureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCapture(this);
}

void EnhancedPGNParser::CaptureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCapture(this);
}

EnhancedPGNParser::CaptureContext* EnhancedPGNParser::capture() {
  CaptureContext *_localctx = _tracker.createInstance<CaptureContext>(_ctx, getState());
  enterRule(_localctx, 68, EnhancedPGNParser::RuleCapture);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EnhancedPGNParser::FILE: {
        enterOuterAlt(_localctx, 1);
        setState(321);
        pawn_capture();
        break;
      }

      case EnhancedPGNParser::PIECE: {
        enterOuterAlt(_localctx, 2);
        setState(322);
        piece_capture();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pawn_captureContext ------------------------------------------------------------------

EnhancedPGNParser::Pawn_captureContext::Pawn_captureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Pawn_captureContext::FILE() {
  return getToken(EnhancedPGNParser::FILE, 0);
}

tree::TerminalNode* EnhancedPGNParser::Pawn_captureContext::CAPTURE_MARKER() {
  return getToken(EnhancedPGNParser::CAPTURE_MARKER, 0);
}

tree::TerminalNode* EnhancedPGNParser::Pawn_captureContext::LOCATION() {
  return getToken(EnhancedPGNParser::LOCATION, 0);
}

tree::TerminalNode* EnhancedPGNParser::Pawn_captureContext::PROMOTION() {
  return getToken(EnhancedPGNParser::PROMOTION, 0);
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::Pawn_captureContext::piece() {
  return getRuleContext<EnhancedPGNParser::PieceContext>(0);
}


size_t EnhancedPGNParser::Pawn_captureContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePawn_capture;
}

void EnhancedPGNParser::Pawn_captureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPawn_capture(this);
}

void EnhancedPGNParser::Pawn_captureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPawn_capture(this);
}

EnhancedPGNParser::Pawn_captureContext* EnhancedPGNParser::pawn_capture() {
  Pawn_captureContext *_localctx = _tracker.createInstance<Pawn_captureContext>(_ctx, getState());
  enterRule(_localctx, 70, EnhancedPGNParser::RulePawn_capture);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(EnhancedPGNParser::FILE);
    setState(326);
    match(EnhancedPGNParser::CAPTURE_MARKER);
    setState(327);
    match(EnhancedPGNParser::LOCATION);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::PROMOTION) {
      setState(328);
      match(EnhancedPGNParser::PROMOTION);
      setState(329);
      piece();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Piece_captureContext ------------------------------------------------------------------

EnhancedPGNParser::Piece_captureContext::Piece_captureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::Piece_captureContext::piece() {
  return getRuleContext<EnhancedPGNParser::PieceContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_captureContext::CAPTURE_MARKER() {
  return getToken(EnhancedPGNParser::CAPTURE_MARKER, 0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_captureContext::LOCATION() {
  return getToken(EnhancedPGNParser::LOCATION, 0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_captureContext::FILE() {
  return getToken(EnhancedPGNParser::FILE, 0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_captureContext::RANK() {
  return getToken(EnhancedPGNParser::RANK, 0);
}


size_t EnhancedPGNParser::Piece_captureContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePiece_capture;
}

void EnhancedPGNParser::Piece_captureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPiece_capture(this);
}

void EnhancedPGNParser::Piece_captureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPiece_capture(this);
}

EnhancedPGNParser::Piece_captureContext* EnhancedPGNParser::piece_capture() {
  Piece_captureContext *_localctx = _tracker.createInstance<Piece_captureContext>(_ctx, getState());
  enterRule(_localctx, 72, EnhancedPGNParser::RulePiece_capture);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    piece();
    setState(334);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::FILE) {
      setState(333);
      match(EnhancedPGNParser::FILE);
    }
    setState(337);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::RANK) {
      setState(336);
      match(EnhancedPGNParser::RANK);
    }
    setState(339);
    match(EnhancedPGNParser::CAPTURE_MARKER);
    setState(340);
    match(EnhancedPGNParser::LOCATION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pawn_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Pawn_moveContext::Pawn_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Pawn_moveContext::LOCATION() {
  return getToken(EnhancedPGNParser::LOCATION, 0);
}

tree::TerminalNode* EnhancedPGNParser::Pawn_moveContext::PROMOTION() {
  return getToken(EnhancedPGNParser::PROMOTION, 0);
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::Pawn_moveContext::piece() {
  return getRuleContext<EnhancedPGNParser::PieceContext>(0);
}


size_t EnhancedPGNParser::Pawn_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePawn_move;
}

void EnhancedPGNParser::Pawn_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPawn_move(this);
}

void EnhancedPGNParser::Pawn_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPawn_move(this);
}

EnhancedPGNParser::Pawn_moveContext* EnhancedPGNParser::pawn_move() {
  Pawn_moveContext *_localctx = _tracker.createInstance<Pawn_moveContext>(_ctx, getState());
  enterRule(_localctx, 74, EnhancedPGNParser::RulePawn_move);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(EnhancedPGNParser::LOCATION);
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::PROMOTION) {
      setState(343);
      match(EnhancedPGNParser::PROMOTION);
      setState(344);
      piece();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PromotionContext ------------------------------------------------------------------

EnhancedPGNParser::PromotionContext::PromotionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::PromotionContext::LOCATION() {
  return getToken(EnhancedPGNParser::LOCATION, 0);
}

tree::TerminalNode* EnhancedPGNParser::PromotionContext::PROMOTION() {
  return getToken(EnhancedPGNParser::PROMOTION, 0);
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::PromotionContext::piece() {
  return getRuleContext<EnhancedPGNParser::PieceContext>(0);
}


size_t EnhancedPGNParser::PromotionContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePromotion;
}

void EnhancedPGNParser::PromotionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPromotion(this);
}

void EnhancedPGNParser::PromotionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPromotion(this);
}

EnhancedPGNParser::PromotionContext* EnhancedPGNParser::promotion() {
  PromotionContext *_localctx = _tracker.createInstance<PromotionContext>(_ctx, getState());
  enterRule(_localctx, 76, EnhancedPGNParser::RulePromotion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    match(EnhancedPGNParser::LOCATION);
    setState(348);
    match(EnhancedPGNParser::PROMOTION);
    setState(349);
    piece();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PieceContext ------------------------------------------------------------------

EnhancedPGNParser::PieceContext::PieceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::PieceContext::PIECE() {
  return getToken(EnhancedPGNParser::PIECE, 0);
}


size_t EnhancedPGNParser::PieceContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePiece;
}

void EnhancedPGNParser::PieceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPiece(this);
}

void EnhancedPGNParser::PieceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPiece(this);
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::piece() {
  PieceContext *_localctx = _tracker.createInstance<PieceContext>(_ctx, getState());
  enterRule(_localctx, 78, EnhancedPGNParser::RulePiece);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(EnhancedPGNParser::PIECE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Piece_moveContext ------------------------------------------------------------------

EnhancedPGNParser::Piece_moveContext::Piece_moveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::PieceContext* EnhancedPGNParser::Piece_moveContext::piece() {
  return getRuleContext<EnhancedPGNParser::PieceContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_moveContext::LOCATION() {
  return getToken(EnhancedPGNParser::LOCATION, 0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_moveContext::RANK() {
  return getToken(EnhancedPGNParser::RANK, 0);
}

tree::TerminalNode* EnhancedPGNParser::Piece_moveContext::FILE() {
  return getToken(EnhancedPGNParser::FILE, 0);
}


size_t EnhancedPGNParser::Piece_moveContext::getRuleIndex() const {
  return EnhancedPGNParser::RulePiece_move;
}

void EnhancedPGNParser::Piece_moveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPiece_move(this);
}

void EnhancedPGNParser::Piece_moveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPiece_move(this);
}

EnhancedPGNParser::Piece_moveContext* EnhancedPGNParser::piece_move() {
  Piece_moveContext *_localctx = _tracker.createInstance<Piece_moveContext>(_ctx, getState());
  enterRule(_localctx, 80, EnhancedPGNParser::RulePiece_move);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    piece();
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::RANK) {
      setState(354);
      match(EnhancedPGNParser::RANK);
    }
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::FILE) {
      setState(357);
      match(EnhancedPGNParser::FILE);
    }
    setState(360);
    match(EnhancedPGNParser::LOCATION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastleContext ------------------------------------------------------------------

EnhancedPGNParser::CastleContext::CastleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::CastleContext::LONG_CASTLE() {
  return getToken(EnhancedPGNParser::LONG_CASTLE, 0);
}

tree::TerminalNode* EnhancedPGNParser::CastleContext::SHORT_CASTLE() {
  return getToken(EnhancedPGNParser::SHORT_CASTLE, 0);
}


size_t EnhancedPGNParser::CastleContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCastle;
}

void EnhancedPGNParser::CastleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastle(this);
}

void EnhancedPGNParser::CastleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastle(this);
}

EnhancedPGNParser::CastleContext* EnhancedPGNParser::castle() {
  CastleContext *_localctx = _tracker.createInstance<CastleContext>(_ctx, getState());
  enterRule(_localctx, 82, EnhancedPGNParser::RuleCastle);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _la = _input->LA(1);
    if (!(_la == EnhancedPGNParser::SHORT_CASTLE

    || _la == EnhancedPGNParser::LONG_CASTLE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_commentContext ------------------------------------------------------------------

EnhancedPGNParser::Block_commentContext::Block_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EnhancedPGNParser::Block_comment_bodyContext* EnhancedPGNParser::Block_commentContext::block_comment_body() {
  return getRuleContext<EnhancedPGNParser::Block_comment_bodyContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::Block_commentContext::BLOCK_COMMENT_END() {
  return getToken(EnhancedPGNParser::BLOCK_COMMENT_END, 0);
}

tree::TerminalNode* EnhancedPGNParser::Block_commentContext::BLOCK_COMMENT_START() {
  return getToken(EnhancedPGNParser::BLOCK_COMMENT_START, 0);
}

tree::TerminalNode* EnhancedPGNParser::Block_commentContext::MOVE_TEXT_START_WITH_COMMENT() {
  return getToken(EnhancedPGNParser::MOVE_TEXT_START_WITH_COMMENT, 0);
}


size_t EnhancedPGNParser::Block_commentContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBlock_comment;
}

void EnhancedPGNParser::Block_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_comment(this);
}

void EnhancedPGNParser::Block_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_comment(this);
}

EnhancedPGNParser::Block_commentContext* EnhancedPGNParser::block_comment() {
  Block_commentContext *_localctx = _tracker.createInstance<Block_commentContext>(_ctx, getState());
  enterRule(_localctx, 84, EnhancedPGNParser::RuleBlock_comment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    _la = _input->LA(1);
    if (!(_la == EnhancedPGNParser::MOVE_TEXT_START_WITH_COMMENT

    || _la == EnhancedPGNParser::BLOCK_COMMENT_START)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(365);
    block_comment_body();
    setState(366);
    match(EnhancedPGNParser::BLOCK_COMMENT_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_comment_bodyContext ------------------------------------------------------------------

EnhancedPGNParser::Block_comment_bodyContext::Block_comment_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EnhancedPGNParser::Block_comment_textContext *> EnhancedPGNParser::Block_comment_bodyContext::block_comment_text() {
  return getRuleContexts<EnhancedPGNParser::Block_comment_textContext>();
}

EnhancedPGNParser::Block_comment_textContext* EnhancedPGNParser::Block_comment_bodyContext::block_comment_text(size_t i) {
  return getRuleContext<EnhancedPGNParser::Block_comment_textContext>(i);
}

std::vector<EnhancedPGNParser::CommandContext *> EnhancedPGNParser::Block_comment_bodyContext::command() {
  return getRuleContexts<EnhancedPGNParser::CommandContext>();
}

EnhancedPGNParser::CommandContext* EnhancedPGNParser::Block_comment_bodyContext::command(size_t i) {
  return getRuleContext<EnhancedPGNParser::CommandContext>(i);
}


size_t EnhancedPGNParser::Block_comment_bodyContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBlock_comment_body;
}

void EnhancedPGNParser::Block_comment_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_comment_body(this);
}

void EnhancedPGNParser::Block_comment_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_comment_body(this);
}

EnhancedPGNParser::Block_comment_bodyContext* EnhancedPGNParser::block_comment_body() {
  Block_comment_bodyContext *_localctx = _tracker.createInstance<Block_comment_bodyContext>(_ctx, getState());
  enterRule(_localctx, 86, EnhancedPGNParser::RuleBlock_comment_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(368);
      block_comment_text();
      break;
    }

    default:
      break;
    }
    setState(374);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EnhancedPGNParser::COMMAND_START) {
      setState(371);
      command();
      setState(376);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EnhancedPGNParser::BLOCK_COMMENT_TEXT) {
      setState(377);
      block_comment_text();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_comment_textContext ------------------------------------------------------------------

EnhancedPGNParser::Block_comment_textContext::Block_comment_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Block_comment_textContext::BLOCK_COMMENT_TEXT() {
  return getToken(EnhancedPGNParser::BLOCK_COMMENT_TEXT, 0);
}


size_t EnhancedPGNParser::Block_comment_textContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleBlock_comment_text;
}

void EnhancedPGNParser::Block_comment_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_comment_text(this);
}

void EnhancedPGNParser::Block_comment_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_comment_text(this);
}

EnhancedPGNParser::Block_comment_textContext* EnhancedPGNParser::block_comment_text() {
  Block_comment_textContext *_localctx = _tracker.createInstance<Block_comment_textContext>(_ctx, getState());
  enterRule(_localctx, 88, EnhancedPGNParser::RuleBlock_comment_text);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(EnhancedPGNParser::BLOCK_COMMENT_TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

EnhancedPGNParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::CommandContext::COMMAND_START() {
  return getToken(EnhancedPGNParser::COMMAND_START, 0);
}

EnhancedPGNParser::Command_idContext* EnhancedPGNParser::CommandContext::command_id() {
  return getRuleContext<EnhancedPGNParser::Command_idContext>(0);
}

EnhancedPGNParser::Command_paramsContext* EnhancedPGNParser::CommandContext::command_params() {
  return getRuleContext<EnhancedPGNParser::Command_paramsContext>(0);
}

tree::TerminalNode* EnhancedPGNParser::CommandContext::COMMAND_END() {
  return getToken(EnhancedPGNParser::COMMAND_END, 0);
}


size_t EnhancedPGNParser::CommandContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCommand;
}

void EnhancedPGNParser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void EnhancedPGNParser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}

EnhancedPGNParser::CommandContext* EnhancedPGNParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 90, EnhancedPGNParser::RuleCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    match(EnhancedPGNParser::COMMAND_START);
    setState(383);
    command_id();
    setState(384);
    command_params();
    setState(385);
    match(EnhancedPGNParser::COMMAND_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Command_idContext ------------------------------------------------------------------

EnhancedPGNParser::Command_idContext::Command_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EnhancedPGNParser::Command_idContext::COMMAND_ID() {
  return getToken(EnhancedPGNParser::COMMAND_ID, 0);
}


size_t EnhancedPGNParser::Command_idContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCommand_id;
}

void EnhancedPGNParser::Command_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand_id(this);
}

void EnhancedPGNParser::Command_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand_id(this);
}

EnhancedPGNParser::Command_idContext* EnhancedPGNParser::command_id() {
  Command_idContext *_localctx = _tracker.createInstance<Command_idContext>(_ctx, getState());
  enterRule(_localctx, 92, EnhancedPGNParser::RuleCommand_id);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(EnhancedPGNParser::COMMAND_ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Command_paramsContext ------------------------------------------------------------------

EnhancedPGNParser::Command_paramsContext::Command_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Command_paramsContext::PARAM_TEXT() {
  return getTokens(EnhancedPGNParser::PARAM_TEXT);
}

tree::TerminalNode* EnhancedPGNParser::Command_paramsContext::PARAM_TEXT(size_t i) {
  return getToken(EnhancedPGNParser::PARAM_TEXT, i);
}

std::vector<tree::TerminalNode *> EnhancedPGNParser::Command_paramsContext::COMMA() {
  return getTokens(EnhancedPGNParser::COMMA);
}

tree::TerminalNode* EnhancedPGNParser::Command_paramsContext::COMMA(size_t i) {
  return getToken(EnhancedPGNParser::COMMA, i);
}


size_t EnhancedPGNParser::Command_paramsContext::getRuleIndex() const {
  return EnhancedPGNParser::RuleCommand_params;
}

void EnhancedPGNParser::Command_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand_params(this);
}

void EnhancedPGNParser::Command_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EnhancedPGNParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand_params(this);
}

EnhancedPGNParser::Command_paramsContext* EnhancedPGNParser::command_params() {
  Command_paramsContext *_localctx = _tracker.createInstance<Command_paramsContext>(_ctx, getState());
  enterRule(_localctx, 94, EnhancedPGNParser::RuleCommand_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(EnhancedPGNParser::PARAM_TEXT);
    setState(394);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EnhancedPGNParser::COMMA) {
      setState(390);
      match(EnhancedPGNParser::COMMA);
      setState(391);
      match(EnhancedPGNParser::PARAM_TEXT);
      setState(396);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void EnhancedPGNParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  enhancedpgnparserParserInitialize();
#else
  ::antlr4::internal::call_once(enhancedpgnparserParserOnceFlag, enhancedpgnparserParserInitialize);
#endif
}
