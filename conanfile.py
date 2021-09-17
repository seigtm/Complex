from conans import ConanFile


class Complex(ConanFile):
    name = "Complex"
    version = "1.1.0"
    author = "Baranov Konstantin (seigtm@gmail.com)"
    url = "https://github.com/seigtm/Complex"
    description = "A simple complex numbers class that supports all basic operations"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    build_requires = \
        "gtest/[1.11]"
