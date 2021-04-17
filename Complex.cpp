#include "Complex.h"

Complex::Complex()
  : real{ 0 }
  , img{ 0 }
{}

Complex::Complex(const double r, const double i)
  : real{ r }
  , img{ i }
{}

Complex& Complex::operator +=(const Complex& other) {
  real += other.real;
  img += other.img;
  return *this;
}

Complex Complex::operator +(double value) {
  Complex result{ *this };
  return (result += Complex(value));
}

Complex Complex::operator-() const
{
  Complex result{ *this };
  result.img *= -1;
  result.real *= -1;
  return result;
}

Complex Complex::operator+() const
{
  return Complex(*this);
}

Complex& Complex::operator -=(const Complex& other) {
  real -= other.real;
  img -= other.img;
  return *this;
}

Complex Complex::operator -(double value) {
  Complex result{ *this };
  return (result -= Complex(value));
}

Complex& Complex::operator *=(const Complex& other) {
  double tempReal{}, tempImg{};
  tempReal = (real * other.real) - (img * other.img);
  tempImg = (img * other.real) + (real * other.img);
  real = tempReal;
  img = tempImg;
  return *this;
}

Complex Complex::operator *(double value) {
  Complex result{ *this };
  return (result *= Complex(value));
}

Complex& Complex::operator /=(const Complex& other) {
  double tempReal{}, tempImg{};
  tempReal = ((real * other.real) + (img * other.img)) / (other.real * other.real + other.img * other.img);
  tempImg = ((img * other.real) - (real * other.img)) / (other.real * other.real + other.img * other.img);
  real = tempReal;
  img = tempImg;
  return *this;
}

Complex Complex::operator /(double value) {
  Complex result{ *this };
  return (result /= Complex(value));
}

Complex cos(const Complex& complex) {
  Complex result{ (std::cos(complex.real) * std::cosh(complex.img)), -((std::sin(complex.real) * std::sinh(complex.img))) };
  return result;
}

Complex sin(const Complex& complex) {
  Complex result{ (std::sin(complex.real) * std::cosh(complex.img)), (std::cos(complex.real) * std::sinh(complex.img)) };
  return result;
}

Complex Complex::operator ++(int) { // ++x.
  Complex result{ *this };
  real++;
  return result;
}

Complex Complex::operator --(int) { // --x.
  Complex result{ *this };
  real--;
  return result;
}

bool Complex::operator ==(const Complex& other) const {
  return (isEqual(other.real, real) && isEqual(other.img, img));
}

bool Complex::operator !=(const Complex& other) const {
  return !(isEqual(other.real, real) || isEqual(other.img, img));
}

std::ostream& operator <<(std::ostream& out, const Complex& complex) {
  out << '(' << complex.real << ", " << complex.img << ')';
  return out;
}

std::istream& operator >>(std::istream& in, Complex& complex) {
  in >> complex.real;
  in >> complex.img;
  return in;
}

Complex& Complex::operator --() {   // x--.
  real--;
  return *this;
}

Complex& Complex::operator ++() {   // x++.
  real++;
  return *this;
}

Complex Complex::operator /(const Complex& other) {
  Complex result{ *this };
  return (result /= other);
}

Complex Complex::operator *(const Complex& other) {
  Complex result{ *this };
  return (result *= other);
}

Complex Complex::operator -(const Complex& other) {
  Complex result{ *this };
  return (result -= other);
}

Complex Complex::operator +(const Complex& other) {
  Complex result{ *this };
  return (result += other);
}

Complex operator +(double value, Complex mc) {
  return (Complex(value) + mc);
}

Complex operator -(double value, Complex mc) {
  return (Complex(value) - mc);
}

Complex operator *(double value, Complex mc) {
  return (Complex(value) * mc);
}

Complex operator /(double value, Complex mc) {
  return (Complex(value) / mc);
}

Complex pow(Complex complex, const double power) {
  double modulus = std::abs(sqrt(complex.real * complex.real + complex.img * complex.img));
  double phi = atan(complex.img / complex.real);
  double real = cos(phi * power);
  double img = sin(phi * power);
  double modulusPower = pow(modulus, power);

  Complex result(modulusPower * real, modulusPower * img);
  return result;
}

Complex nrt(Complex complex, const double power) {
  return pow(complex, 1 / power);
}
