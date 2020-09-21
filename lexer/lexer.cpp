#include <memory>
#include <iostream>
#include "lexer.h"
#include <string>

std::unique_ptr<Lexer> create_lexer(std::string cont) {
    std::unique_ptr<Lexer> lexer = std::make_unique<Lexer>();
    lexer->contents = cont;
    lexer->i = 0;
    lexer->c = cont[lexer->i];

    return lexer;
}

