#include <iostream>
#include <string>

class SyntaxAnalyzer : public ReadAdapter{
private:
    std::string stack_brackets;

public:
    SyntaxAnalyzer() {
        stack_brackets = "";
    }

    void read(char ch) override{
        std::cout<<ch<<std::endl;
    }

    std::string analysis() {
        return "yes";
    }
};