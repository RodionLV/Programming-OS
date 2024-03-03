#include <string>

class ReadAdapter {
public:
    virtual void read(std::string& str){};

    virtual void read(char c){};
};

