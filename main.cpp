#include <iostream>

#include <complex.hpp>

using namespace setm;

int main() {
    const Complex a{ 3.2, -5.0 };
    const Complex b{ -1.2, 5.0 };
    std::cout << a << " + " << b << " = " << a + b << "\n";

    return 0;
}
