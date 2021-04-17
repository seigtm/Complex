#pragma once
#include <iostream>
#include <cmath>

class Complex {

public:
  Complex();
  Complex(double r, double i = 0);

  // Addition operators.
  Complex& operator += (const Complex& other);
  Complex operator + (const Complex& other);
  Complex operator + (double value);
  friend Complex operator + (double value, Complex mc);

  // Unary operators.
  Complex operator - () const;
  Complex operator + () const;

  // Substraction operators.
  Complex& operator -= (const Complex& other);
  Complex operator - (const Complex& other);
  Complex operator - (double value);
  friend Complex operator - (double value, Complex mc);

  // Multiplication operators.
  Complex& operator *= (const Complex& other);
  Complex operator * (const Complex& other);
  Complex operator * (double value);
  friend Complex operator * (double value, Complex mc);

  // Division operators.
  Complex& operator /= (const Complex& other);
  Complex operator / (const Complex& other);
  Complex operator / (double value);
  friend Complex operator / (double value, Complex mc);

  // Exponentiation using de Moivre's formula.
  friend Complex pow(Complex complex, double power);

  // nth root using power.
  friend Complex nrt(Complex complex, double power);

  // Trigonometric functions.
  friend Complex sin(const Complex& complex);
  friend Complex cos(const Complex& complex);

  // Increment operators.
  Complex& operator ++ ();   // x++.
  Complex operator ++ (int); // ++x.

  // Decrement operators.
  Complex& operator -- ();   // x--.
  Complex operator -- (int); // --x.

  // Comparison operators.
  bool operator ==(const Complex& other) const;
  bool operator !=(const Complex& other) const;

  template<class T>
  bool operator ==(const T& other) const {
    if (!isEqual(img, 0.0))
      return false;

    return isEqual(real, other);
  }

  template<class T>
  bool operator !=(const T& other) const {
    if (isEqual(img, 0.0))
      return !isEqual(real, other);

    return true;
  }

  template<class T>
  friend bool operator ==(const T& other, const Complex& complex) {
    return complex == other;
  }

  template<class T>
  friend bool operator !=(const T& other, const Complex& complex) {
    return complex != other;
  }

  // Bitwise operators.
  friend std::ostream& operator <<(std::ostream& out, const Complex& complex);
  friend std::istream& operator >>(std::istream& in, Complex& complex);


private:
  double real;
  double img;

  template<class T>
  bool isEqual(const double& a, const T& b) const {
    return a == b;
  }

  bool isEqual(const double& a, const double& b) const {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
  }
};

// Friend functions:
Complex operator + (double value, Complex mc);
Complex operator - (double value, Complex mc);
Complex operator * (double value, Complex mc);
Complex operator / (double value, Complex mc);

Complex sin(const Complex& complex);
Complex cos(const Complex& complex);

Complex pow(Complex complex, const double power); // Exponentiation.
Complex nrt(Complex complex, const double power); // nth root.

std::ostream& operator <<(std::ostream& out, const Complex& complex);
std::istream& operator >>(std::istream& in, Complex& complex);
