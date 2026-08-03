"""Conanfile module for this project."""
from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import can_run
from conan.tools.cmake import CMake, cmake_layout


class ProjectConan(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'CMakeDeps', 'CMakeToolchain'

    def layout(self):
        cmake_layout(self)

    def validate(self):
        cppstd = self.settings.get_safe('compiler.cppstd')
        if cppstd is not None and int(str(cppstd).removeprefix('gnu')) < 23:
            raise ConanInvalidConfiguration('TypeSafeRegister requires C++23.')

    def build_requirements(self):
        if can_run(self):
            self.test_requires('catch2/3.15.2')

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
