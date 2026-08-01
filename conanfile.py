"""Conanfile module for this project."""
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain


class ProjectConan(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    default_options = {'fmt/*:header_only': True}
    generators = 'CMakeDeps', 'CMakeToolchain'

    def _uses_legacy_format(self):
        cppstd = self.settings.get_safe('compiler.cppstd')
        return cppstd is not None and int(str(cppstd).removeprefix('gnu')) < 20

    def requirements(self):
        if self._uses_legacy_format():
            self.requires('fmt/11.2.0')
        if self.settings.get_safe('arch') == 'armv7':
            return

        self.requires('catch2/3.9.1')

    def configure(self):
        cmake = CMakeToolchain(self)
        cmake.user_presets_path = None

    def build(self):
        cmake = CMakeToolchain(self)
        cmake.configure()
        cmake.build()
