#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "core/BatCave.hpp" 

namespace py = pybind11;

PYBIND11_MODULE(bat_bit, m) {
    m.doc() = "Bat-Bit v2.0: Full Data Structure Suite";
    
    // 1. BatCave (Sets)
    py::class_<BatCave>(m, "BatCave")
        .def(py::init<>())
        .def("deploy", &BatCave::deploy)
        .def("deploy_batch", &BatCave::deploy_batch)
        .def("signal", &BatCave::signal)
        .def("memory_usage", &BatCave::wayne_tech_specs);

    // 2. BatVector (Arrays)
    py::class_<BatVector>(m, "BatVector")
        .def(py::init<>())
        .def("push", &BatVector::push)
        .def("push_batch", &BatVector::push_batch)
        .def("get", &BatVector::get)
        .def("set", &BatVector::set)
        .def("__len__", &BatVector::size) // len(vec)
        .def("__getitem__", &BatVector::get) // vec[0]
        .def("__setitem__", &BatVector::set) // vec[0] = 5
        .def("memory_usage", &BatVector::memory_usage);

    // 3. BatMap (Dictionaries)
    py::class_<BatMap>(m, "BatMap")
        .def(py::init<>())
        .def("put", &BatMap::put)
        .def("put_batch", &BatMap::put_batch)
        .def("get", &BatMap::get)
        .def("contains", &BatMap::contains)
        .def("__getitem__", &BatMap::get)
        .def("__setitem__", &BatMap::put)
        .def("__contains__", &BatMap::contains) // key in map
        .def("memory_usage", &BatMap::memory_usage);

    // 4. BatStore (OOP Engine)
    py::class_<BatStore>(m, "BatStore")
        .def(py::init<>())
        // Schema Definition
        .def("add_int_col", &BatStore::add_int_col)
        .def("add_float_col", &BatStore::add_float_col)
        .def("add_str_col", &BatStore::add_str_col)
        // Operations
        .def("new_row", &BatStore::new_row)
        // Setters
        .def("set_int", &BatStore::set_int)
        .def("set_float", &BatStore::set_float)
        .def("set_str", &BatStore::set_str)
        // Getters
        .def("get_int", &BatStore::get_int)
        .def("get_float", &BatStore::get_float)
        .def("get_str", &BatStore::get_str)
        
        .def("memory_usage", &BatStore::memory_usage);
}