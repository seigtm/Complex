#include <cmath>

#include <gtest/gtest.h>

#include "complex.hpp"

using namespace setm;

TEST(ComplexTests, Assigment) {
    Complex first{ 5, -5 };
    Complex second;
    // (5 - 5 * i) != 0
    EXPECT_NE(first, second);

    // (5 - 5 * i) == (5 - 5 * i)
    second = first;
    EXPECT_EQ(first, second);

    // (-12.1 + 0 * i) == (-12.1 + 0 * i)
    second = -12.1;
    EXPECT_EQ(second, Complex(-12.1, 0));
}

TEST(ComplexTests, Comparison) {
    // (1 - 5 * i) == (1 - 5 * i)
    EXPECT_EQ(Complex(1, -5), Complex(1, -5));

    // (3 + 3 * i) != (3.001 + 3.001 * i)
    EXPECT_NE(Complex(3, 3), Complex(3.001, 3.001));

    // Int-> double.
    EXPECT_EQ(Complex(3, 5), Complex(3.0, 5.0));

    // Complex() == Complex(0) == Complex(0, 0)
    EXPECT_TRUE(Complex() == Complex(0));
    EXPECT_TRUE(Complex(0) == Complex(0, 0));
    EXPECT_TRUE(Complex() == Complex(0, 0));

    // 3.3 == (3.3 + 0 * i)
    EXPECT_EQ(3.3, Complex(3.3));

    // (3.3 + 0.1 * i) != 3.3
    EXPECT_NE(Complex(3.3, 0.1), 3.3);
    EXPECT_NE(3.3, Complex(3.3, 0.1));
}

TEST(ComplexTests, Unary) {
    EXPECT_EQ(Complex(12, -7), +Complex(12, -7));
    EXPECT_EQ(Complex(0, -3), -Complex(0, 3));
}

TEST(ComplexTests, Addition) {
    // ((1 - 5 * i) + (1 + 2.1 * i)) == (2 + 7.1 * i)
    EXPECT_EQ(Complex(1, -5) + Complex(1, 2.1), Complex(2, -2.9));

    // ((3 - 5 * i) + 3.01) == (6.01 - 5 * i)
    EXPECT_EQ(Complex(3, -5) + 3.01, Complex(6.01, -5));

    // (-12.8 + (12.8 + 0 * i)) == 0
    EXPECT_EQ(-12.8 + Complex(12.8), Complex());
    EXPECT_EQ(-12.8 + Complex(12.8), 0);
}

TEST(ComplexTests, Substraction) {
    // ((2 - 5 * i) - (-2 + 5 * i)) == (4 - 10 * i)
    EXPECT_EQ(Complex(2, -5) - Complex(-2, 5), Complex(4, -10));

    // (3 - (3 + 0 * i)) == 0
    EXPECT_EQ(3 - Complex(3.0, 0.0), 0);

    // ((-5 + i) - (0 + i)) == -5
    EXPECT_EQ(Complex(-5, 1) - Complex(0, 1), -5);

    // ((3 + 0 * i) - 3) == 0
    EXPECT_EQ(Complex(3) - 3, Complex());
}

TEST(ComplexTests, Multiplication) {
    // ((12.1 - 0.1 * i) * (1 - 1 * i)) == (12 - 12.2 * i)
    EXPECT_EQ(Complex(12.1, -0.1) * Complex(1, -1), Complex(12, -12.2));

    // (5 * (-3 - 3 * i)) == (-15 - 15 * i)
    EXPECT_EQ(5 * Complex(-3, -3), Complex(-15, -15));

    // ((8.0001 - 2.002 * i) * 0.003) == (0.0240003 - 0.006006 * i)
    EXPECT_EQ(Complex(8.0001, -2.002) * 0.003, Complex(0.0240003, -0.006006));
}

TEST(ComplexTests, Division) {
    // ((10 - 2 * i) / (0 + 2 * i)) == (-1 - 5 * i)
    EXPECT_EQ(Complex(10, -2) / Complex(0, 2), Complex(-1, -5));

    // (0.1 / (-5 + 5 * i)) == (-0.01 - 0.01 * i)
    EXPECT_EQ(0.1 / Complex(-5, 5), Complex(-0.01, -0.01));

    // ((10 + 0 * i) / 5) == 2
    EXPECT_EQ(Complex(10) / 5, 2);
}

TEST(ComplexTests, Exponentiation) {
    // (1 + 1 * i)^5 == (-4 - 4 * i)
    EXPECT_EQ(pow(Complex(1, 1), 5), Complex(-4, -4));

    // (5 - 5 * i)^2 == (0 - 50 * i)
    EXPECT_EQ(pow(Complex(5, -5), 2), Complex(0, -50));
}

TEST(ComplexTests, Root) {
    // sqrt((4 + 0 * i)) == 2
    EXPECT_EQ(nrt(Complex(4), 2), 2);

    // nrt((64 + 0 * i), 3) == (4 + 0 * i)
    EXPECT_EQ(nrt(Complex(64), 3), Complex(4));

    // sqrt((5 + 5 * i)) == (5 + 5 * i)^0.5
    EXPECT_EQ(nrt(Complex(5, 5), 2), pow(Complex(5, 5), 0.5));
}

TEST(ComplexTests, Trigonometric) {
    // Sine.
    // sin(1 + 0 * i) == sin(1)
    EXPECT_EQ(sin(Complex(1)), std::sin(1));
    // sin(0 + 1 * i) == (0 + sinh(1) * i)
    EXPECT_EQ(sin(Complex(0, 1)), Complex(0, std::sinh(1)));

    // Cosine.
    // cos(1 + 0 * i) == cos(1)
    EXPECT_EQ(cos(Complex(1)), std::cos(1));
    // cos(0 + 1 * i) == cosh(1)
    EXPECT_EQ(cos(Complex(0, 1)), std::cosh(1));

    // Magnitude (abs).
    // (1 + 1 * i) magnitude is always ~1.4142135623730951.
    EXPECT_EQ(abs(Complex(1, 1)), 1.4142135623730951);
}
