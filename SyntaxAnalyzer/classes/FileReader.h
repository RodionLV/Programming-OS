#include <iostream>
#include <fstream>

#include "./ReadAdapter.h"

class FileReader {
public:
    static void read(const std::string& filename, ReadAdapter& adapter) {
        std::ifstream file(filename);

        if (file.is_open()) {
            while (!file.eof()) {
                adapter.read(file.get());
            }
        } else {
            file.close();
            throw std::ifstream::failure("Not open file");
        }

        file.close();
    }
};
