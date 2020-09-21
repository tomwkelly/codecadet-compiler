#include "gtest/gtest.h"
#include "../src/lexer/lexer.h"
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;
TEST(LexerTest, CreatesLexer) {
    string file("print a;");
   
    unique_ptr<Lexer> l = create_lexer(file);

    EXPECT_TRUE(l);
}

TEST(LexerTest, IncrementsChar) {
   string file("print a;");

   unique_ptr<Lexer> l = create_lexer(file);

   char c = l->c;
   
   l->advance();

   EXPECT_NE(c, l->c);
   
}
