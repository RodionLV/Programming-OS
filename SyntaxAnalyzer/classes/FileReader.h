#include <iostream>
#include <fstream>

#include "./ReadAdapter.h"

class FileReader {
public:
    static void read(const std::string& filename, ReadAdapter& adapter) {
        std::ifstream file(filename);

        if (file.is_open()) {
            int pos = 1, line = 1;

            while (!file.eof()) {
                char ch = file.get();

                adapter.read(ch, pos, line);

                pos++;
                if(ch == '\n'){
                    line++;
                    pos = 1;
                }
            }
        } else {
            file.close();
            throw std::ifstream::failure("Not open file");
        }

        file.close();
    }
};
