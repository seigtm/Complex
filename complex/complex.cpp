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

bool Complex::operator==(const Complex &other) const noexcept {
    constexpr double epsilon{ 2.22e-12L };
    return abs(*this - other) <= epsilon;
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

Complex Complex::operator/(const Complex &other) const {
    Complex result{ *this };
    return (result /= other);
}

double Complex::getReal() const noexcept {
    return real;
}

double Complex::getImg() const noexcept {
    return img;
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

Complex operator+(double value, const Complex &complex) {
    return (complex + value);
}

Complex operator-(double value, const Complex &complex) {
    return (Complex{ value } - complex);
}

Complex operator*(double value, const Complex &complex) {
    return (complex * value);
}

Complex operator/(double value, const Complex &complex) {
    return (Complex{ value } / complex);
}

Complex pow(const Complex &complex, double power) {
    double phi{ std::atan(complex.img / complex.real) };
    double real{ std::cos(phi * power) };
    double img{ std::sin(phi * power) };
    double modulusPower{ std::pow(abs(complex), power) };

    return { modulusPower * real, modulusPower * img };
}

Complex nrt(const Complex &complex, double power) {
    return pow(complex, static_cast<double>(1.0 / power));
}

double abs(const Complex &complex) {
    return std::sqrt(complex.real * complex.real + complex.img * complex.img);
}

}  // namespace setm
