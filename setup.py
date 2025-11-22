from setuptools import setup, Extension
import pybind11
import os

# Read the long description from python/README.md
with open(os.path.join("python", "README.md"), "r", encoding="utf-8") as fh:
    long_description = fh.read()

# Define the C++ extension
ext_modules = [
    Extension(
        "bat_bit",              # The name of the module to import in Python
        ["python/bat_python.cpp"],        # The source file
        include_dirs=[pybind11.get_include(), "core"], # Added core include dir just in case
        language="c++",
        extra_compile_args=["-O3"] # Maximum Optimization Flag
    ),
]

setup(
    name="bat-bit",
    version="1.2.1",
    description="The Dark Knight of Data Structures - High-Performance C++ Sparse Bitset for Python.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    author="Bruce Wayne", # Keeping the theme, user can change if needed
    url="https://github.com/mahmoudkarsli1998/Bat-Bit", # Inferring from user info
    ext_modules=ext_modules,
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Programming Language :: C++",
    ],
    python_requires='>=3.7',
)