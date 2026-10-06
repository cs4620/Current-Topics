// 08_struct_methods.cpp
#include <iostream>
#include <cmath>

struct Vector3D {
    float x;
    float y;
    float z;

    // 1. Constructor: Called automatically when an object is created.
    // Uses a member initializer list (x(initX), etc.) for efficiency.
    Vector3D(float initX = 0.0f, float initY = 0.0f, float initZ = 0.0f)
        : x(initX), y(initY), z(initZ) {}

    // 2. Member function: Operates directly on internal fields (x, y, z).
    // Marked 'const' because it reads data without modifying the struct.
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // 3. Member function that modifies internal state
    void normalize() {
        float len = length();
        if (len > 0.0f) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    // 4. Print helper method
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    // Uses the default constructor (0, 0, 0)
    Vector3D v1;
    std::cout << "v1 (default): ";
    v1.print();

    // Uses the custom constructor
    Vector3D v2(3.0f, 0.0f, 4.0f);
    std::cout << "v2 (custom):  ";
    v2.print();

    // Call member functions directly on the object using dot operator
    std::cout << "v2 Length: " << v2.length() << "\n";

    v2.normalize();
    std::cout << "v2 Normalized: ";
    v2.print();
    std::cout << "v2 New Length: " << v2.length() << "\n";

    return 0;
}