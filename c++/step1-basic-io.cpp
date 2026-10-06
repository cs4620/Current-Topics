// 01_iostream_basics.cpp
#include <iostream>

int main() {
    int count = 100;
    float scale = 2.5f;

    // Automatic type formatting and chaining with <<
    std::cout << "Count: " << count << ", Scale: " << scale << "\n";

    // Reading input with >>
    std::cout << "Enter a new scale factor: ";
    std::cin >> scale;

    std::cout << "Updated Scale: " << scale << "\n";
    return 0;
}