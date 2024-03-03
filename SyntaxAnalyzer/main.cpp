#include <iostream>
#include <fstream>

#include "./classes/FileReader.h"
#include "classes/BracketsAnalyzer.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    try{
        BracketsAnalyzer syntax_ba;

        FileReader::read("./files/code.txt", syntax_ba);

        ofstream out;
        out.open("./files/out.txt", ios::out);

        string res = syntax_ba.analysis();
        cout<<"Результат проверки скобок case 1: "<<res<<endl;
        out << "code.txt: "<<res<<"\n";

        syntax_ba.reset();

        FileReader::read("./files/err-code.txt", syntax_ba);

        res = syntax_ba.analysis();
        cout<<"Результат проверки скобок case 2: "<<res<<endl;
        out << "err-code.txt: "<<res<<"\n";

        out.close();
    }catch(const exception& e){
        cout<<e.what()<<endl;
    }

    return 0;
}
