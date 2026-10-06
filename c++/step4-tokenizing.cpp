// 04_stringstream_parsing.cpp
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line = "v 1.5 -2.0 0.25";

    // Wrap the string in a stream
    std::stringstream ss(line);

    std::string prefix;
    float x, y, z;

    // Extract values token by token (delimited by spaces)
    ss >> prefix >> x >> y >> z;

    std::cout << "Parsed Prefix: " << prefix << "\n";
    std::cout << "Parsed Coordinates: (" << x << ", " << y << ", " << z << ")\n";

    return 0;
}