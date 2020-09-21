#ifndef fileReader_h
#define fileReader_h

#include <memory>
#include <fstream>
#include <string>

using std::unique_ptr;
using std::string;

unique_ptr<char[]> FileReader(string fileName){
   std::ifstream fstream (fileName, std::ifstream::binary);
   if(fstream) {
    // get length of file:
    fstream.seekg(0, fstream.end);
    int length = fstream.tellg();
    fstream.seekg(0, fstream.beg);
   
    
   unique_ptr<char[]> buffer = std::make_unique<char[]>(length);

   fstream.read(buffer.get(), length);

   fstream.close();

   return buffer;
   }
   return NULL;
}  
#endif
