// 05_file_reading.cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("sample.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open sample.txt!\n";
        return 1;
    }

    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        std::cout << "LINE: " << line << "\n";
    }

    // File closes automatically here when 'file' goes out of scope
    return 0;
}