#ifndef token_h
#define token_h
#include <string>

#include "tokenTypes.h"

struct Token {
    TokenType type;
    std::string value;

    Token(){};

    Token(TokenType t, std::string v) {
        type = t;
        value = v;
    };
};

#endif
