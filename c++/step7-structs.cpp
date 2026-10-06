// 07_obj_parser_mini.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Vec3 {
    float x, y, z;
};

int main() {
    std::ifstream file("cube.obj");
    if (!file.is_open()) {
        std::cerr << "Failed to open cube.obj\n";
        return 1;
    }

    std::vector<Vec3> vertices;
    std::string line;

    while (std::getline(file, line)) {
        // Skip empty lines or comment lines
        if (line.empty() || line[0] == '#') {
            continue;
        }

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        // Process vertex data
        if (type == "v") {
            Vec3 v;
            ss >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        }
    }

    std::cout << "Successfully parsed " << vertices.size() << " vertices.\n";
    return 0;
}