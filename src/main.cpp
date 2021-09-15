#include <iostream>

#include "complex.hpp"

using namespace setm;

void printTwoComplex(const Complex &first, const Complex &second) {
    std::cout << "First = " << first << std::endl
              << "Second = " << second << std::endl
              << std::endl;
}

int main() {
    std::cout << "~~~ COMPLEX NUMBERS ~~~\n\n";

    // Bitwise
    std::cout << "Enter the first complex number = ";
    Complex first;
    std::cin >> first;
    std::cout << "First = " << first << std::endl
              << std::endl;

    std::cout << "Enter the second complex number = ";
    Complex second;
    std::cin >> second;
    std::cout << "Second = " << second << std::endl
              << std::endl;

    printTwoComplex(first, second);

    // Addition
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Addition" << std::endl;
    std::cout << "first + second = \t" << first + second << std::endl;
    std::cout << "first + -12.9 = \t" << first + -12.9 << std::endl;
    std::cout << "14.2 + second = \t" << 14.2 + second << std::endl;
    std::cout << "first += second = \t" << (first += second) << "\n~~~~~~~~~~~~~~\n\n";

    // Substraction
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Substraction" << std::endl;
    std::cout << "first - second = \t" << first - second << std::endl;
    std::cout << "first - -12.9 = \t" << first - -12.9 << std::endl;
    std::cout << "14.2 - second = \t" << 14.2 - second << std::endl;
    std::cout << "first -= second = \t" << (first -= second) << "\n~~~~~~~~~~~~~~\n\n";

    // Multiplication
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Multiplication" << std::endl;
    std::cout << "first * second = \t" << first * second << std::endl;
    std::cout << "first * -12.9 = \t" << first * -12.9 << std::endl;
    std::cout << "14.2 * second = \t" << 14.2 * second << std::endl;
    std::cout << "first *= second = \t" << (first *= second) << "\n~~~~~~~~~~~~~~\n\n";

    // Division
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Division" << std::endl;
    std::cout << "first / second = \t" << first / second << std::endl;
    std::cout << "first / -12.9 = \t" << first / -12.9 << std::endl;
    std::cout << "14.2 / second = \t" << 14.2 / second << std::endl;
    std::cout << "first /= second = \t" << (first /= second) << "\n~~~~~~~~~~~~~~\n\n";

    // Comparison (equality)
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Comparison (equality)" << std::endl;
    std::cout << "first == second = \t" << (first == second) << std::endl;
    std::cout << "first != 5.2 = \t" << (first != 5.2) << std::endl;
    std::cout << "5 == second = \t" << (5 == second) << std::endl;
    std::cout << "first != second = \t" << (first != second) << "\n~~~~~~~~~~~~~~\n\n";

    // Unary
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Unary" << std::endl;
    std::cout << "+first = \t" << +first << std::endl;
    std::cout << "-second = \t" << -second << std::endl;
    std::cout << "-first = \t" << -first << std::endl;
    std::cout << "+second = \t" << +second << "\n~~~~~~~~~~~~~~\n\n";

    // Exponentiation using de Moivre's formula
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Exponentiation using de Moivre's formula" << std::endl;
    std::cout << "pow(first, 3.0) = \t" << pow(first, 3.0) << std::endl;
    std::cout << "pow(second, -12) = \t" << pow(second, -12) << "\n~~~~~~~~~~~~~~\n\n";  // Not sure about it.

    // nth root using power
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "nth root using power" << std::endl;
    std::cout << "nrt(first, 3.0) = \t" << nrt(first, 3.0) << std::endl;
    std::cout << "nrt(second, -12) = \t" << nrt(second, -12) << "\n~~~~~~~~~~~~~~\n\n";

    // Trigonometric functions
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Trigonometric functions" << std::endl;
    std::cout << "sin(first) = \t" << sin(first) << std::endl;
    std::cout << "cos(second) = \t" << cos(second) << "\n~~~~~~~~~~~~~~\n\n";

    // Increment and decrement
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Increment and decrement" << std::endl;
    std::cout << "first++ && second--:" << std::endl;
    first++;
    second++;
    printTwoComplex(first, second);
    std::cout << "++first && --second:" << std::endl;
    std::cout << "++first = \t" << ++first << std::endl;
    std::cout << "--second = \t" << --second << "\n~~~~~~~~~~~~~~\n\n";

    // Assignment
    printTwoComplex(first, second);
    std::cout << "~~~~~~~~~~~~~~\n"
              << "Assigment" << std::endl;
    first = second;
    std::cout << "first = second\n";
    printTwoComplex(first, second);
}
