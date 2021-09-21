from conans import ConanFile, CMake


class Complex(ConanFile):
    name = "Complex"
    version = "1.3.0"

    # Metadata.
    author = "Baranov Konstantin (seigtm@gmail.com)"
    url = "https://github.com/seigtm/Complex"
    description = "A simple complex numbers class that supports all basic operations"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    # Packages requirements.
    build_requires = \
        "gtest/[1.11]"

    # Version control specification.
    scm = {
        "type": "git",
        "subfolder": name,
        "url": "auto",
        "revision": "auto",
        "username": "git"
    }

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder = self.name)
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.configure(source_folder = self.name)
        cmake.install()
