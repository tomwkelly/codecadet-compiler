#ifndef token_h
#define token_h
#include "tokenTypes.h"
#include <string>

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, std::string v){
        type = t;
        value = v;
    };
};


#endif
