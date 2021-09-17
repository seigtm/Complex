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
    friend Complex operator+(double value, const Complex &complex);

    // Unary operators.
    Complex operator-() const noexcept;
    Complex operator+() const noexcept;

    // Substraction operators.
    Complex &operator-=(const Complex &other);
    Complex operator-(const Complex &other) const;
    Complex operator-(double value) const;
    friend Complex operator-(double value, const Complex &complex);

    // Multiplication operators.
    Complex &operator*=(const Complex &other);
    Complex operator*(const Complex &other) const;
    Complex operator*(double value) const;
    friend Complex operator*(double value, const Complex &complex);

    // Division operators.
    Complex &operator/=(const Complex &other);
    Complex operator/(const Complex &other) const;
    Complex operator/(double value) const;
    friend Complex operator/(double value, const Complex &complex);

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

    // Trigonometric.
    friend double abs(const Complex &complex);   // Magnitude.
    friend Complex sin(const Complex &complex);  // Sine.
    friend Complex cos(const Complex &complex);  // Cosine.

    // Exponentiation and nth root.
    friend Complex pow(const Complex &complex, double power);  // Exponentiation using de Moivre's formula.
    friend Complex nrt(const Complex &complex, double power);  // nth root using pow().

    // Real and imaginary parts getters.
    double getReal() const noexcept;
    double getImg() const noexcept;

private:
    double real;
    double img;
};

}  // namespace setm
