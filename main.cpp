#include <memory>
#include <string>
#include "./src/shared/fileReader.h"
#include "./src/lexer/lexer.h"
#include <iostream>
#include <chrono>

using std::cout;
using std::string;
int main(int argc, char** argv){
    if (argc != 2){
        cout << "Usage: cccp <file>" << std::endl;
        return 1;
    }

    string fileName(argv[1]);

    unique_ptr<char[]> file = FileReader(fileName);

    auto start = std::chrono::system_clock::now();

    unique_ptr<Lexer> l =  create_lexer(string(file.get()));


    l->create_tokens();

    for(size_t i = 0; i < l-> tokenList.size(); ++i)
    {

        cout << l->tokenList[i].value << ' ' << l-> tokenList[i].type << std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start).count();

    std::cout << "Total runtime: " << duration << std::endl;

    return 0;
}
