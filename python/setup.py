from setuptools import setup, Extension
import pybind11
import os

# Read the long description from README.md
with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

# Define the C++ extension
ext_modules = [
    Extension(
        "bat_bit",
        ["bat_python.cpp"],
        include_dirs=[pybind11.get_include(), "."],
        language="c++",
        extra_compile_args=["/O2", "/std:c++17"]
    ),
]

setup(
    name="bat-bit",
    version="1.2.1",
    description="The Dark Knight of Data Structures - High-Performance C++ Sparse Bitset for Python.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    author="Bruce Wayne",
    url="https://github.com/mahmoudkarsli1998/Bat-Bit",
    ext_modules=ext_modules,
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Programming Language :: C++",
    ],
    python_requires='>=3.7',
)