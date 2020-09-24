#ifndef keywords_h
#define keywords_h
#include <string>
#include <unordered_map>

#include "../shared/tokenTypes.h"

static const std::unordered_map<std::string, TokenType> Keywords = {
    {"number", KEYWORD_NUMBER},   {"string", KEYWORD_STRING},
    {"print", KEYWORD_PRINT},     {"for", KEYWORD_FOR},
    {"foreach", KEYWORD_FOREACH}, {"if", KEYWORD_IF},
    {"else", KEYWORD_ELSE},       {"while", KEYWORD_WHILE}};

#endif
