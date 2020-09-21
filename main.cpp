#include <memory>
#include <string>
#include "./shared/fileReader.h"
#include "./lexer/lexer.h"
#include <iostream>

using std::cout;
using std::string;
int main(int argc, char** argv){
    if (argc != 2){
        cout << "Usage: cccp <file>" << std::endl;
        return 1;
    }

    string fileName(argv[1]);

    unique_ptr<char[]> file = FileReader(fileName);

    unique_ptr<Lexer> l =  create_lexer(string(file.get()));


    l->create_tokens();

    for(size_t i = 0; i < l-> tokenList.size(); ++i)
    {

        cout << l->tokenList[i].value << ' ' << l-> tokenList[i].type << std::endl;
    }

    return 0;
}
