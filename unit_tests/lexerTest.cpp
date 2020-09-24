#include <memory>
#include <string>

#include "../src/lexer/lexer.h"
#include "gtest/gtest.h"

using std::string;
using std::unique_ptr;
TEST(LexerTest, CreatesLexer) {
    string file("print a;");

    std::unique_ptr<Lexer> lp = std::make_unique<Lexer>(file);

    EXPECT_TRUE(lp);
}

TEST(LexerTest, IncrementsChar) {
    string file("print a;");

    Lexer l(file);

    char c = l.c;

    l.advance();

    EXPECT_NE(c, l.c);
}
