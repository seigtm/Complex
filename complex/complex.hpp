#pragma once

#include <cmath>

#include <iostream>
#include <limits>

namespace setm {

class Complex {
public:
    Complex();
    Complex(double r, double i = 0);

    // Addition operators.
    Complex &operator+=(const Complex &other);
    Complex operator+(const Complex &other) const;
    Complex operator+(double value) const;
    friend Complex operator+(double value, Complex complex);

    // Unary operators.
    Complex operator-() const noexcept;
    Complex operator+() const noexcept;

    // Substraction operators.
    Complex &operator-=(const Complex &other);
    Complex operator-(const Complex &other) const;
    Complex operator-(double value) const;
    friend Complex operator-(double value, Complex complex);

    // Multiplication operators.
    Complex &operator*=(const Complex &other);
    Complex operator*(const Complex &other) const;
    Complex operator*(double value) const;
    friend Complex operator*(double value, Complex complex);

    // Division operators.
    Complex &operator/=(const Complex &other);
    Complex operator/(const Complex &other) const;
    Complex operator/(double value) const;
    friend Complex operator/(double value, Complex complex);

    // Exponentiation using de Moivre's formula.
    friend Complex pow(Complex complex, double power);

    // nth root using power.
    friend Complex nrt(Complex complex, double power);

    // Trigonometric functions.
    friend Complex sin(const Complex &complex);
    friend Complex cos(const Complex &complex);

    // Increment operators.
    Complex &operator++();    // x++.
    Complex operator++(int);  // ++x.

    // Decrement operators.
    Complex &operator--();    // x--.
    Complex operator--(int);  // --x.

    // Comparison operators.
    bool operator==(const Complex &other) const noexcept;
    bool operator!=(const Complex &other) const noexcept;
    bool operator==(double other) const noexcept;
    bool operator!=(double other) const noexcept;
    friend bool operator==(double other, const Complex &complex) noexcept;
    friend bool operator!=(double other, const Complex &complex) noexcept;

    // Bitwise operators.
    friend std::ostream &operator<<(std::ostream &out, const Complex &complex);
    friend std::istream &operator>>(std::istream &in, Complex &complex);

    // Friend functions:
    friend Complex operator+(double value, Complex complex);
    friend Complex operator-(double value, Complex complex);
    friend Complex operator*(double value, Complex complex);
    friend Complex operator/(double value, Complex complex);

    friend Complex sin(const Complex &complex);
    friend Complex cos(const Complex &complex);

    friend Complex pow(Complex complex, double power);  // Exponentiation.
    friend Complex nrt(Complex complex, double power);  // nth root.

    friend std::ostream &operator<<(std::ostream &out, const Complex &complex);
    friend std::istream &operator>>(std::istream &in, Complex &complex);

private:
    double real;
    double img;

    bool isEqual(double a, double b) const noexcept;
};

}  // namespace setm
