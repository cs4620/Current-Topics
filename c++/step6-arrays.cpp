// 06_vector_basics.cpp
#include <iostream>
#include <vector>

struct Point {
    float x, y;
};

int main() {
    // Replaces: Point* points = malloc(sizeof(Point) * count);
    std::vector<Point> points;

    // Add elements dynamically
    points.push_back({0.0f, 1.0f});
    points.push_back({2.0f, -1.0f});

    std::cout << "Total points: " << points.size() << "\n";

    // Modern C++ range-based loop
    for (const auto& p : points) {
        std::cout << "Point: (" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}