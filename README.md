# Complex number C++ class

> In mathematics, a complex number is a number that can be expressed in the form a + bi, where a and b are real numbers, and i is a symbol called the imaginary unit, and satisfying the equation i^2 = -1.  
> (https://en.wikipedia.org/wiki/Complex_number)

---

## Constructors:

Default constructor without parameters:

```c++
Complex();
```

Constructor with parameters:

```c++
// double r is real number.
// double i is imaginary unit.
Complex(double r, double i = 0);
```

---

## List of supported operators and functions:

- unary;
- addition;
- substraction;
- multiplication;
- division;
- exponentiation (using [de Moivre's formula](https://en.wikipedia.org/wiki/De_Moivre%27s_formula));
- nth root (using power);
- trigonometric (sin and cos);
- comparison (equality);
- bitwise (for std::cin and std::cout).
