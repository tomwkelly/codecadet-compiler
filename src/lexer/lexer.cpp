#include "lexer.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../shared/token.h"
#include "../shared/tokenTypes.h"
#include "keywords.h"

Lexer::Lexer(std::string cont) : contents(cont), i(0), c(cont[0]) {}

void Lexer::create_tokens() {
    Token token;
    while ((token = get_next_token()).type != ENDF) {
        tokenList.push_back(token);
    }
};

void Lexer::advance() {
    if (c != '\0' && i < contents.length()) {
        i += 1;
        c = contents[i];
    }
};

Token Lexer::advance_with_token(Token token) {
    advance();

    return token;
};

void Lexer::skip_whitespace() {
    while (c == ' ' || c == 10) {
        advance();
    }
};

Token Lexer::get_next_token() {
    while (c != '\0' && i < contents.length()) {
        if (c == ' ' || c == 10) skip_whitespace();

        if (isdigit(c)) return get_number();

        if (isalnum(c)) {
            return get_id();
        }

        if (c == '"' || c == '\'') return get_string();

        switch (c) {
            case ')':
                return advance_with_token(Token(RPAREN, get_current_str()));
                break;

            case '(':
                return advance_with_token(Token(LPAREN, get_current_str()));
                break;

            case ';':
                return advance_with_token(Token(SEMIC, get_current_str()));
                break;

            case '=':
                return advance_with_token(Token(ASSIGN, get_current_str()));
                break;
        }
    }

    return Token(ENDF, get_current_str());
};

Token Lexer::get_id() {
    std::stringstream val;

    while (std::isalnum(c)) {
        val << get_current_str();
        advance();
    }

    std::string res = val.str();

    auto found = Keywords.find(res);

    if (found != Keywords.end()) return Token(found->second, res);

    return Token(ID, val.str());
};

Token Lexer::get_number() {
    std::stringstream val;

    while (std::isdigit(c) || c == '.') {
        val << get_current_str();
        advance();
    }

    return Token(NUMBER, val.str());
}

Token Lexer::get_string() {
    char quote = c;
    advance();

    std::stringstream val;

    while (c != quote) {
        val << get_current_str();
        advance();
    }

    advance();

    return Token(STRING, val.str());
};

std::string Lexer::get_current_str() { return std::string(1, c); };
