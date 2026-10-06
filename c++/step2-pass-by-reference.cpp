// 02_references.cpp
#include <iostream>

// C style: void scale_c(float* x, float factor) { *x *= factor; }
// C++ style: x is an alias to the original variable
void scale(float& x, float factor) {
    x *= factor;
}

int main() {
    float val = 10.0f;
    
    // Pass 'val' directly—no '&' needed at the call site
    scale(val, 1.5f);

    std::cout << "Scaled value: " << val << "\n"; // Outputs 15
    return 0;
}