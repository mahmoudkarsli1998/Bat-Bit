// /*
//  * BAT-BIT ENGINE 🦇
//  * The High-Performance, Sparse Bitset for Python.
//  * * Logic:
//  * - The "BatCave" is the main container.
//  * - It uses "UtilityBelts" (Pages) to store bits.
//  * - If a number is not in a belt, that belt doesn't exist in RAM.
//  */

// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>
// #include "../core/BatCave.hpp" // هنا الربط بالمخ

// namespace py = pybind11;

// // Python Binding Code
// PYBIND11_MODULE(bat_bit, m) {
//     m.doc() = "Bat-Bit: O(1) Speed, Zero Bloat."; 

//     py::class_<BatCave>(m, "BatCave")
//         .def(py::init<>())
//         .def("deploy", &BatCave::deploy, "Add a number to the set")
//         .def("signal", &BatCave::signal, "Check if a number exists")
//         .def("memory_usage", &BatCave::wayne_tech_specs, "Get current RAM usage in bytes");
// }
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Important for automatic vector conversion
#include "../core/BatCave.hpp"

namespace py = pybind11;

PYBIND11_MODULE(bat_bit, m) {
    m.doc() = "Bat-Bit Mark II: Hypersonic Speed";
    
    py::class_<BatCave>(m, "BatCave")
        .def(py::init<>())
        .def("deploy", &BatCave::deploy)
        .def("deploy_batch", &BatCave::deploy_batch, "Insert millions instantly") // New Function
        .def("signal", &BatCave::signal)
        .def("memory_usage", &BatCave::wayne_tech_specs);
}