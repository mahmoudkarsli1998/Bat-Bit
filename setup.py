from setuptools import setup, Extension
import pybind11

# Define the C++ extension
ext_modules = [
    Extension(
        "bat_bit",              # The name of the module to import in Python
        ["python/bat_python.cpp"],        # The source file
        include_dirs=[pybind11.get_include()],
        language="c++",
        extra_compile_args=["-O3"] # Maximum Optimization Flag
    ),
]

setup(
    name="bat-bit",
    version="1.0.0",
    description="The Dark Knight of Data Structures.",
    author="Bruce Wayne",
    ext_modules=ext_modules,
)