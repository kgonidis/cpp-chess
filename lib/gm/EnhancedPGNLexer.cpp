
// Generated from EnhancedPGNLexer.g4 by ANTLR 4.13.1


#include "EnhancedPGNLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct EnhancedPGNLexerStaticData final {
  EnhancedPGNLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  EnhancedPGNLexerStaticData(const EnhancedPGNLexerStaticData&) = delete;
  EnhancedPGNLexerStaticData(EnhancedPGNLexerStaticData&&) = delete;
  EnhancedPGNLexerStaticData& operator=(const EnhancedPGNLexerStaticData&) = delete;
  EnhancedPGNLexerStaticData& operator=(EnhancedPGNLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag enhancedpgnlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
EnhancedPGNLexerStaticData *enhancedpgnlexerLexerStaticData = nullptr;

void enhancedpgnlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (enhancedpgnlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(enhancedpgnlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<EnhancedPGNLexerStaticData>(
    std::vector<std::string>{
      "TAG_START", "STRING", "MOVE_TEXT_START", "MOVE_TEXT_START_WITH_COMMENT", 
      "NEW_LINE", "TAG_END", "TAG_VALUE", "TAG_KEY", "TAG_SPACE", "EOL_COMMENT_START", 
      "MOVE_NUM", "BLOCK_COMMENT_START", "WS", "PIECE", "LOCATION", "PROMOTION", 
      "RANK", "FILE", "SHORT_CASTLE", "LONG_CASTLE", "CAPTURE_MARKER", "ALTERNATE_LINE_START", 
      "ALTERNATE_LINE_END", "BLUNDER", "MISTAKE", "DUBIOUS_MOVE", "INTERESTING_MOVE", 
      "GOOD_MOVE", "BRILLIANT_MOVE", "CHECK", "CHECKMATE", "WHITE_WINS", 
      "BLACK_WINS", "DRAW", "UNKOWN_ENDING", "NAG", "EOL_COMMENT_TEXT", 
      "EOL_COMMENT_END", "COMMAND_START", "BLOCK_COMMENT_END", "BLOCK_COMMENT_TEXT", 
      "COMMAND_ID", "COMMAND_END", "COMMA", "PARAM_TEXT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "TAG_PAIRS", "MOVE_TEXT", "EOL_COMMENT", "BLOCK_COMMENT", 
      "COMMAND", "COMMAND_PARAMS"
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
  	4,0,45,296,6,-1,6,-1,6,-1,6,-1,6,-1,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,
  	2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,
  	7,11,2,12,7,12,2,13,7,13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,
  	7,18,2,19,7,19,2,20,7,20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,
  	7,25,2,26,7,26,2,27,7,27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,
  	7,32,2,33,7,33,2,34,7,34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,
  	7,39,2,40,7,40,2,41,7,41,2,42,7,42,2,43,7,43,2,44,7,44,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,108,8,1,10,1,12,1,111,9,1,1,1,1,1,1,2,4,
  	2,116,8,2,11,2,12,2,117,1,2,1,2,3,2,122,8,2,1,2,3,2,125,8,2,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,137,8,4,1,5,1,5,1,5,1,5,1,6,1,6,1,7,
  	4,7,146,8,7,11,7,12,7,147,1,8,1,8,1,9,1,9,1,9,1,9,1,10,4,10,157,8,10,
  	11,10,12,10,158,1,10,1,10,3,10,163,8,10,1,10,3,10,166,8,10,1,11,1,11,
  	1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,16,
  	1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,
  	1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,31,
  	1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,
  	1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,35,1,35,4,35,251,8,35,
  	11,35,12,35,252,1,36,4,36,256,8,36,11,36,12,36,257,1,37,1,37,1,37,1,37,
  	1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,40,4,40,274,8,40,11,40,
  	12,40,275,1,41,4,41,279,8,41,11,41,12,41,280,1,41,1,41,1,42,1,42,1,42,
  	1,42,1,42,1,43,1,43,1,44,4,44,293,8,44,11,44,12,44,294,0,0,45,7,1,9,2,
  	11,3,13,4,15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,
  	37,16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,
  	27,61,28,63,29,65,30,67,31,69,32,71,33,73,34,75,35,77,36,79,37,81,38,
  	83,39,85,40,87,41,89,42,91,43,93,44,95,45,7,0,1,2,3,4,5,6,11,2,0,34,34,
  	92,92,1,0,48,57,4,0,48,57,65,90,95,95,97,122,3,0,10,10,13,13,32,32,4,
  	0,66,66,75,75,78,78,81,82,1,0,49,56,1,0,97,104,1,0,10,10,2,0,91,91,125,
  	125,3,0,48,57,65,90,97,122,2,0,44,44,93,93,305,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,1,19,1,0,0,0,1,
  	21,1,0,0,0,1,23,1,0,0,0,2,25,1,0,0,0,2,27,1,0,0,0,2,29,1,0,0,0,2,31,1,
  	0,0,0,2,33,1,0,0,0,2,35,1,0,0,0,2,37,1,0,0,0,2,39,1,0,0,0,2,41,1,0,0,
  	0,2,43,1,0,0,0,2,45,1,0,0,0,2,47,1,0,0,0,2,49,1,0,0,0,2,51,1,0,0,0,2,
  	53,1,0,0,0,2,55,1,0,0,0,2,57,1,0,0,0,2,59,1,0,0,0,2,61,1,0,0,0,2,63,1,
  	0,0,0,2,65,1,0,0,0,2,67,1,0,0,0,2,69,1,0,0,0,2,71,1,0,0,0,2,73,1,0,0,
  	0,2,75,1,0,0,0,2,77,1,0,0,0,3,79,1,0,0,0,3,81,1,0,0,0,4,83,1,0,0,0,4,
  	85,1,0,0,0,4,87,1,0,0,0,5,89,1,0,0,0,6,91,1,0,0,0,6,93,1,0,0,0,6,95,1,
  	0,0,0,7,97,1,0,0,0,9,101,1,0,0,0,11,115,1,0,0,0,13,128,1,0,0,0,15,136,
  	1,0,0,0,17,138,1,0,0,0,19,142,1,0,0,0,21,145,1,0,0,0,23,149,1,0,0,0,25,
  	151,1,0,0,0,27,156,1,0,0,0,29,167,1,0,0,0,31,171,1,0,0,0,33,175,1,0,0,
  	0,35,177,1,0,0,0,37,180,1,0,0,0,39,182,1,0,0,0,41,184,1,0,0,0,43,186,
  	1,0,0,0,45,190,1,0,0,0,47,196,1,0,0,0,49,198,1,0,0,0,51,200,1,0,0,0,53,
  	202,1,0,0,0,55,205,1,0,0,0,57,207,1,0,0,0,59,210,1,0,0,0,61,213,1,0,0,
  	0,63,215,1,0,0,0,65,218,1,0,0,0,67,220,1,0,0,0,69,222,1,0,0,0,71,228,
  	1,0,0,0,73,234,1,0,0,0,75,244,1,0,0,0,77,248,1,0,0,0,79,255,1,0,0,0,81,
  	259,1,0,0,0,83,263,1,0,0,0,85,268,1,0,0,0,87,273,1,0,0,0,89,278,1,0,0,
  	0,91,284,1,0,0,0,93,289,1,0,0,0,95,292,1,0,0,0,97,98,5,91,0,0,98,99,1,
  	0,0,0,99,100,6,0,0,0,100,8,1,0,0,0,101,109,5,34,0,0,102,103,5,92,0,0,
  	103,108,5,92,0,0,104,105,5,92,0,0,105,108,5,34,0,0,106,108,8,0,0,0,107,
  	102,1,0,0,0,107,104,1,0,0,0,107,106,1,0,0,0,108,111,1,0,0,0,109,107,1,
  	0,0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,109,1,0,0,0,112,113,5,34,0,
  	0,113,10,1,0,0,0,114,116,7,1,0,0,115,114,1,0,0,0,116,117,1,0,0,0,117,
  	115,1,0,0,0,117,118,1,0,0,0,118,119,1,0,0,0,119,121,5,46,0,0,120,122,
  	5,46,0,0,121,120,1,0,0,0,121,122,1,0,0,0,122,124,1,0,0,0,123,125,5,46,
  	0,0,124,123,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,127,6,2,1,0,127,
  	12,1,0,0,0,128,129,5,123,0,0,129,130,1,0,0,0,130,131,6,3,1,0,131,132,
  	6,3,2,0,132,14,1,0,0,0,133,137,5,10,0,0,134,135,5,13,0,0,135,137,5,10,
  	0,0,136,133,1,0,0,0,136,134,1,0,0,0,137,16,1,0,0,0,138,139,5,93,0,0,139,
  	140,1,0,0,0,140,141,6,5,3,0,141,18,1,0,0,0,142,143,3,9,1,0,143,20,1,0,
  	0,0,144,146,7,2,0,0,145,144,1,0,0,0,146,147,1,0,0,0,147,145,1,0,0,0,147,
  	148,1,0,0,0,148,22,1,0,0,0,149,150,5,32,0,0,150,24,1,0,0,0,151,152,5,
  	59,0,0,152,153,1,0,0,0,153,154,6,9,4,0,154,26,1,0,0,0,155,157,7,1,0,0,
  	156,155,1,0,0,0,157,158,1,0,0,0,158,156,1,0,0,0,158,159,1,0,0,0,159,160,
  	1,0,0,0,160,162,5,46,0,0,161,163,5,46,0,0,162,161,1,0,0,0,162,163,1,0,
  	0,0,163,165,1,0,0,0,164,166,5,46,0,0,165,164,1,0,0,0,165,166,1,0,0,0,
  	166,28,1,0,0,0,167,168,5,123,0,0,168,169,1,0,0,0,169,170,6,11,2,0,170,
  	30,1,0,0,0,171,172,7,3,0,0,172,173,1,0,0,0,173,174,6,12,5,0,174,32,1,
  	0,0,0,175,176,7,4,0,0,176,34,1,0,0,0,177,178,3,41,17,0,178,179,3,39,16,
  	0,179,36,1,0,0,0,180,181,5,61,0,0,181,38,1,0,0,0,182,183,7,5,0,0,183,
  	40,1,0,0,0,184,185,7,6,0,0,185,42,1,0,0,0,186,187,5,79,0,0,187,188,5,
  	45,0,0,188,189,5,79,0,0,189,44,1,0,0,0,190,191,5,79,0,0,191,192,5,45,
  	0,0,192,193,5,79,0,0,193,194,5,45,0,0,194,195,5,79,0,0,195,46,1,0,0,0,
  	196,197,5,120,0,0,197,48,1,0,0,0,198,199,5,40,0,0,199,50,1,0,0,0,200,
  	201,5,41,0,0,201,52,1,0,0,0,202,203,5,63,0,0,203,204,5,63,0,0,204,54,
  	1,0,0,0,205,206,5,63,0,0,206,56,1,0,0,0,207,208,5,63,0,0,208,209,5,33,
  	0,0,209,58,1,0,0,0,210,211,5,33,0,0,211,212,5,63,0,0,212,60,1,0,0,0,213,
  	214,5,33,0,0,214,62,1,0,0,0,215,216,5,33,0,0,216,217,5,33,0,0,217,64,
  	1,0,0,0,218,219,5,43,0,0,219,66,1,0,0,0,220,221,5,35,0,0,221,68,1,0,0,
  	0,222,223,5,49,0,0,223,224,5,45,0,0,224,225,5,48,0,0,225,226,1,0,0,0,
  	226,227,6,31,3,0,227,70,1,0,0,0,228,229,5,48,0,0,229,230,5,45,0,0,230,
  	231,5,49,0,0,231,232,1,0,0,0,232,233,6,32,3,0,233,72,1,0,0,0,234,235,
  	5,49,0,0,235,236,5,47,0,0,236,237,5,50,0,0,237,238,5,45,0,0,238,239,5,
  	49,0,0,239,240,5,47,0,0,240,241,5,50,0,0,241,242,1,0,0,0,242,243,6,33,
  	3,0,243,74,1,0,0,0,244,245,5,42,0,0,245,246,1,0,0,0,246,247,6,34,3,0,
  	247,76,1,0,0,0,248,250,5,36,0,0,249,251,7,1,0,0,250,249,1,0,0,0,251,252,
  	1,0,0,0,252,250,1,0,0,0,252,253,1,0,0,0,253,78,1,0,0,0,254,256,8,7,0,
  	0,255,254,1,0,0,0,256,257,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,
  	80,1,0,0,0,259,260,5,10,0,0,260,261,1,0,0,0,261,262,6,37,3,0,262,82,1,
  	0,0,0,263,264,5,91,0,0,264,265,5,37,0,0,265,266,1,0,0,0,266,267,6,38,
  	6,0,267,84,1,0,0,0,268,269,5,125,0,0,269,270,1,0,0,0,270,271,6,39,3,0,
  	271,86,1,0,0,0,272,274,8,8,0,0,273,272,1,0,0,0,274,275,1,0,0,0,275,273,
  	1,0,0,0,275,276,1,0,0,0,276,88,1,0,0,0,277,279,7,9,0,0,278,277,1,0,0,
  	0,279,280,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,282,1,0,0,0,282,
  	283,6,41,7,0,283,90,1,0,0,0,284,285,5,93,0,0,285,286,1,0,0,0,286,287,
  	6,42,3,0,287,288,6,42,3,0,288,92,1,0,0,0,289,290,5,44,0,0,290,94,1,0,
  	0,0,291,293,8,10,0,0,292,291,1,0,0,0,293,294,1,0,0,0,294,292,1,0,0,0,
  	294,295,1,0,0,0,295,96,1,0,0,0,22,0,1,2,3,4,5,6,107,109,117,121,124,136,
  	147,158,162,165,252,257,275,280,294,8,5,1,0,5,2,0,5,4,0,4,0,0,5,3,0,6,
  	0,0,5,5,0,5,6,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  enhancedpgnlexerLexerStaticData = staticData.release();
}

}

EnhancedPGNLexer::EnhancedPGNLexer(CharStream *input) : Lexer(input) {
  EnhancedPGNLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *enhancedpgnlexerLexerStaticData->atn, enhancedpgnlexerLexerStaticData->decisionToDFA, enhancedpgnlexerLexerStaticData->sharedContextCache);
}

EnhancedPGNLexer::~EnhancedPGNLexer() {
  delete _interpreter;
}

std::string EnhancedPGNLexer::getGrammarFileName() const {
  return "EnhancedPGNLexer.g4";
}

const std::vector<std::string>& EnhancedPGNLexer::getRuleNames() const {
  return enhancedpgnlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& EnhancedPGNLexer::getChannelNames() const {
  return enhancedpgnlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& EnhancedPGNLexer::getModeNames() const {
  return enhancedpgnlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& EnhancedPGNLexer::getVocabulary() const {
  return enhancedpgnlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView EnhancedPGNLexer::getSerializedATN() const {
  return enhancedpgnlexerLexerStaticData->serializedATN;
}

const atn::ATN& EnhancedPGNLexer::getATN() const {
  return *enhancedpgnlexerLexerStaticData->atn;
}




void EnhancedPGNLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  enhancedpgnlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(enhancedpgnlexerLexerOnceFlag, enhancedpgnlexerLexerInitialize);
#endif
}
