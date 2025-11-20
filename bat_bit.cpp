/*
 * BAT-BIT ENGINE 🦇
 * The High-Performance, Sparse Bitset for Python.
 * * Logic:
 * - The "BatCave" is the main container.
 * - It uses "UtilityBelts" (Pages) to store bits.
 * - If a number is not in a belt, that belt doesn't exist in RAM.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <unordered_map>

namespace py = pybind11;

class BatCave {
private:
    // Page Size: 65,536 bits (8KB). Ideally fits in L1/L2 CPU Cache.
    static const uint64_t PAGE_SIZE_BITS = 65536; 
    
    struct UtilityBelt {
        std::vector<uint64_t> gadgets;
        
        UtilityBelt() {
            // Resize to hold PAGE_SIZE_BITS. 
            // We divide by 64 because each uint64_t holds 64 bits.
            gadgets.resize(PAGE_SIZE_BITS / 64, 0);
        }
    };

    // The Sparse Map: Key (Sector ID) -> Value (Pointer to Belt)
    std::unordered_map<uint64_t, UtilityBelt*> gotham_city;

public:
    // Constructor
    BatCave() {}

    // Destructor: Clean up memory leaks like Batman cleans up crime
    ~BatCave() {
        for (auto& pair : gotham_city) {
            delete pair.second;
        }
    }

    // DEPLOY: Insert a number (O(1))
    void deploy(uint64_t number) {
        uint64_t sector_id = number / PAGE_SIZE_BITS;
        uint64_t gadget_loc = number % PAGE_SIZE_BITS;
        
        // Lazy Allocation: Only create the belt if we need it
        if (gotham_city.find(sector_id) == gotham_city.end()) {
            gotham_city[sector_id] = new UtilityBelt();
        }

        // Activate the bit
        gotham_city[sector_id]->gadgets[gadget_loc / 64] |= (1ULL << (gadget_loc % 64));
    }

    // SIGNAL: Check if number exists (O(1))
    bool signal(uint64_t number) {
        uint64_t sector_id = number / PAGE_SIZE_BITS;
        uint64_t gadget_loc = number % PAGE_SIZE_BITS;
        
        // If the sector is empty (NULL), the villain isn't there
        if (gotham_city.find(sector_id) == gotham_city.end()) {
            return false;
        }

        // Check the specific bit
        return (gotham_city[sector_id]->gadgets[gadget_loc / 64] & (1ULL << (gadget_loc % 64))) != 0;
    }

    // WAYNE TECH SPECS: Calculate RAM usage in Bytes
    size_t wayne_tech_specs() {
        size_t size = sizeof(*this);
        // Overhead of the map structure + The actual data pages
        size += gotham_city.size() * (sizeof(uint64_t) + sizeof(UtilityBelt*) + sizeof(UtilityBelt)); 
        size += gotham_city.size() * (PAGE_SIZE_BITS / 8);
        return size;
    }
};

// Python Binding Code
PYBIND11_MODULE(bat_bit, m) {
    m.doc() = "Bat-Bit: O(1) Speed, Zero Bloat."; 

    py::class_<BatCave>(m, "BatCave")
        .def(py::init<>())
        .def("deploy", &BatCave::deploy, "Add a number to the set")
        .def("signal", &BatCave::signal, "Check if a number exists")
        .def("memory_usage", &BatCave::wayne_tech_specs, "Get current RAM usage in bytes");
}