from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "bat_bit",
        ["bat_python.cpp"],
        include_dirs=[pybind11.get_include(), "../core"], # ضيفنا المسار ده
        language="c++",
        extra_compile_args=["/O2"] 
    ),
]

setup(name="bat-bit", version="1.1.0", ext_modules=ext_modules)