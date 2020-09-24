#ifndef Lexer_h
#define Lexer_h
#include <string>
#include <vector>

#include "../shared/token.h"

class Lexer {
   public:
    std::vector<Token> tokenList;
    Lexer(std::string cont);
    void create_tokens();
    const std::string contents;  // contents to be parsed
    unsigned int i;              // current index
    char c;                      // current char
    void advance();

   private:
    Token advance_with_token(Token token);

    void skip_whitespace();

    Token get_next_token();

    Token get_id();

    bool is_keyword(std::string val);

    Token get_number();

    Token get_string();

    std::string get_current_str();
};

#endif
