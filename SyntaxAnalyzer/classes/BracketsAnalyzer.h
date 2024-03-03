#include <iostream>
#include <string>
#include <map>

using namespace std;
   
class BracketsAnalyzer : public ReadAdapter{
private:
    string readed_braces = "";

    struct Position{
        int pos;
        int line;

        public:
            Position(){}
            Position(int pos, int line) : pos{pos}, line{line}{}
    };

    map<int, Position> indexed_positions;

    map<char, char> valid_braces = {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}
    };

    int validate(string& braces) {
        if( braces.length() == 0 ){
            return -1;
        }
        if( (int)valid_braces[braces[0]] == 0){
            return 0;
        }

        string stack = "";
        stack += braces[0];

        for(int i = 1; i < braces.length(); i++){
            if( (int)valid_braces[braces[i]] != 0){
                stack += braces[i];
                continue;
            }
            
            if( valid_braces[stack.back()] == braces[i] ){
                stack.erase(stack.length()-1, stack.length());
                continue;
            }
            return i;
        }

        if(stack == ""){
            return -1;
        }else{
            return braces.length()-1;
        }
    }
public:
    void read(char ch, int pos, int line) override{
        for(const auto& element : valid_braces){
            if( ch == element.first || ch == element.second ){
                readed_braces += ch;

                Position p(pos, line);

                indexed_positions[readed_braces.length()-1] = p;
                break;
            }
        }
    }

    string analysis() {
        int index = validate(readed_braces);
        if( index == -1 ){
            return "succesfully";
        }else{
            Position p = indexed_positions[index];

            return "error in line: "+to_string(p.line)+" and col: "+to_string(p.pos);
        }
    }

    void reset(){
        readed_braces = "";
    }
};