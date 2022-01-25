from conans import ConanFile, tools
from conans.errors import ConanInvalidConfiguration
import os


class ReprConan(ConanFile):
    name = "repr"
    description = "repr(value) returns a printable string representation of value"
    topics = ("conan", "repr", "serialization", "header-only")
    url = "https://github.com/conan-io/conan-center-index"
    homepage = "https://github.com/sanblch/repr"
    license = "MIT"
    settings = "compiler"

    @property
    def _source_subfolder(self):
        return "source_subfolder"

    @property
    def _minimum_cpp_standard(self):
        return 17

    @property
    def _compilers_minimum_version(self):
        return {
            "apple-clang": "10",
            "clang": "5",
            "gcc": "9",
            "Visual Studio": "15",
        }

    def configure(self):
        if self.settings.compiler.get_safe("cppstd"):
            tools.check_min_cppstd(self, self._minimum_cpp_standard)

        compiler = self.settings.compiler
        try:
            min_version = self._compilers_minimum_version[str(compiler)]
            if tools.Version(compiler.version) < min_version:
                msg = (
                    "{} requires C++{} features which are not supported by compiler {} {}."
                ).format(self.name, self._minimum_cpp_standard, compiler, compiler.version)
                raise ConanInvalidConfiguration(msg)
        except KeyError:
            msg = (
                "{} recipe lacks information about the {} compiler, "
                "support for the required C++{} features is assumed"
            ).format(self.name, compiler, self._minimum_cpp_standard)
            self.output.warn(msg)

    def requirements(self):
        self.requires("fmt/8.1.1")
        self.requires("magic_enum/0.7.3")
        self.requires("pfr/2.0.2")

    def source(self):
        tools.get(**self.conan_data["sources"][self.version][0])
        extracted_dir = self.name + "-" + self.version
        os.rename(extracted_dir, self._source_subfolder)

    def package(self):
        self.copy("*", dst="include",
                  src=os.path.join(self._source_subfolder, "include"))
        self.copy("LICENSE", dst="licenses", src=self._source_subfolder)

    def package_id(self):
        self.info.header_only()
