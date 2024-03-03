#include <iostream>

#include "./classes/FileReader.h"
#include "classes/SyntaxAnalyzer.h"

using namespace std;

int main() {

    try{
        SyntaxAnalyzer syntax_a;

        FileReader::read("./files/code.txt", syntax_a);

        
    }catch(const exception& e){
        cout<<e.what()<<endl;
    }

    return 0;
}
