#include "gtest/gtest.h"
#include "../src/lexer/lexer.h"
#include <string>
#include <memory>

TEST(LexerTest, CreatesLexer) {
    std::string file("print a;");
   
    std::unique_ptr<Lexer> l = create_lexer(file);

    EXPECT_TRUE(l);
}
