#include "complex.hpp"

namespace setm {

Complex::Complex()
    : real{}, img{} {
}

Complex::Complex(double r, double i)
    : real{ r }, img{ i } {
}

Complex &Complex::operator+=(const Complex &other) {
    real += other.real;
    img += other.img;
    return *this;
}

Complex Complex::operator+(double value) const {
    Complex result{ *this };
    return (result += value);
}

Complex Complex::operator-() const noexcept {
    return { -real, -img };
}

Complex Complex::operator+() const noexcept {
    return *this;
}

Complex &Complex::operator-=(const Complex &other) {
    real -= other.real;
    img -= other.img;
    return *this;
}

Complex Complex::operator-(double value) const {
    Complex result{ *this };
    return (result -= value);
}

Complex &Complex::operator*=(const Complex &other) {
    double tempReal, tempImg;
    tempReal = (real * other.real) - (img * other.img);
    tempImg = (img * other.real) + (real * other.img);
    real = tempReal;
    img = tempImg;
    return *this;
}

Complex Complex::operator*(double value) const {
    Complex result{ *this };
    return (result *= value);
}

Complex &Complex::operator/=(const Complex &other) {
    double tempReal, tempImg;
    tempReal = ((real * other.real) + (img * other.img)) / (other.real * other.real + other.img * other.img);
    tempImg = ((img * other.real) - (real * other.img)) / (other.real * other.real + other.img * other.img);
    real = tempReal;
    img = tempImg;
    return *this;
}

Complex Complex::operator/(double value) const {
    Complex result{ *this };
    return (result /= value);
}

Complex cos(const Complex &complex) {
    return { (std::cos(complex.real) * std::cosh(complex.img)), -(std::sin(complex.real) * std::sinh(complex.img)) };
}

Complex sin(const Complex &complex) {
    return { (std::sin(complex.real) * std::cosh(complex.img)), (std::cos(complex.real) * std::sinh(complex.img)) };
}

Complex Complex::operator++(int) {  // ++x.
    Complex result{ *this };
    real++;
    return result;
}

Complex Complex::operator--(int) {  // --x.
    Complex result{ *this };
    real--;
    return result;
}

bool Complex::operator==(const Complex &other) const noexcept {
    return (isEqual(other.real, real) && isEqual(other.img, img));
}

bool Complex::operator!=(const Complex &other) const noexcept {
    return !(*this == other);
}

bool Complex::operator==(double other) const noexcept {
    return (*this == Complex{ other });
}

bool Complex::operator!=(double other) const noexcept {
    return !(*this == Complex{ other });
}

bool operator==(double other, const Complex &complex) noexcept {
    return (complex == other);
}

bool operator!=(double other, const Complex &complex) noexcept {
    return !(complex == other);
}

std::ostream &operator<<(std::ostream &out, const Complex &complex) {
    out << '(' << complex.real << ", " << complex.img << ')';
    return out;
}

std::istream &operator>>(std::istream &in, Complex &complex) {
    in >> complex.real >> complex.img;
    return in;
}

Complex &Complex::operator--() {  // x--.
    real--;
    return *this;
}

Complex &Complex::operator++() {  // x++.
    real++;
    return *this;
}

Complex Complex::operator/(const Complex &other) const {
    Complex result{ *this };
    return (result /= other);
}

Complex Complex::operator*(const Complex &other) const {
    Complex result{ *this };
    return (result *= other);
}

Complex Complex::operator-(const Complex &other) const {
    Complex result{ *this };
    return (result -= other);
}

Complex Complex::operator+(const Complex &other) const {
    Complex result{ *this };
    return (result += other);
}

Complex operator+(double value, Complex complex) {
    return (complex + value);
}

Complex operator-(double value, Complex complex) {
    return (Complex{ value } - complex);
}

Complex operator*(double value, Complex complex) {
    return (complex * value);
}

Complex operator/(double value, Complex complex) {
    return (Complex{ value } / complex);
}

Complex pow(Complex complex, double power) {
    double modulus{ std::abs(std::sqrt(complex.real * complex.real + complex.img * complex.img)) };
    double phi{ std::atan(complex.img / complex.real) };
    double real{ std::cos(phi * power) };
    double img{ std::sin(phi * power) };
    double modulusPower{ std::pow(modulus, power) };

    return { modulusPower * real, modulusPower * img };
}

Complex nrt(Complex complex, double power) {
    return pow(complex, 1.0 / power);
}

bool Complex::isEqual(double a, double b) const noexcept {
    return std::fabs(a - b) <= std::numeric_limits<double>::epsilon();
}

}  // namespace setm
