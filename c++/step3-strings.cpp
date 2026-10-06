// 03_string_basics.cpp
#include <iostream>
#include <string>

int main() {
    std::string filename = "mesh";
    
    // Concatenation with +
    filename = filename + ".obj";
    std::cout << "Filename: " << filename << "\n";

    // Useful string methods
    std::cout << "Length: " << filename.length() << "\n";
    
    // Check if filename ends with ".obj"
    if (filename.find(".obj") != std::string::npos) {
        std::cout << "Valid OBJ file extension found.\n";
    }

    return 0;
}