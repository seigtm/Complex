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

- get real and imaginary units;
- unary;
- addition;
- substraction;
- multiplication;
- division;
- exponentiation (using [de Moivre's formula](https://en.wikipedia.org/wiki/De_Moivre%27s_formula));
- nth root (using power);
- trigonometric (sine, cosine and magnitude(abs));
- comparison (equality);
- bitwise (for std::cin and std::cout).

## Cloning the repository:

```bash
bash> git clone https://github.com/seigtm/Complex
```

---

## Build requirements:

- [cmake](https://cmake.org/) to configure the project (minimum required version is **3.5**).
- [conan](https://conan.io/) to download all application dependencies.  
  You can install **conan** by giving a command to **pip**:
  ```bash
  bash> pip install --user conan
  ```
  To use **pip** you need to install the **python** interpreter. I highly recommend to install **python3**-based versions in order to avoid unexpected results when using **conan**.

---

## Configuring and build with conan and cmake:

To install with `conan`, execute the commands:

```bash
bash> cd Complex
bash> conan install . -if build --build missing
```

To build and run the project with `cmake`, execute:

```bash
bash> cd build
bash> cmake ..
```

To install and run the application, execute:

```bash
bash> make
bash> cd bin
bash> ./main
```
