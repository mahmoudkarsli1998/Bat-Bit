// #pragma once
// #include <vector>
// #include <unordered_map>
// #include <cstdint>

// class BatCave {
// private:
//     static const uint64_t PAGE_SIZE_BITS = 65536; 
    
//     struct UtilityBelt {
//         std::vector<uint64_t> gadgets;
//         UtilityBelt() {
//             gadgets.resize(PAGE_SIZE_BITS / 64, 0);
//         }
//     };

//     std::unordered_map<uint64_t, UtilityBelt*> gotham_city;

// public:
//     BatCave() {}
    
//     ~BatCave() {
//         for (auto& pair : gotham_city) delete pair.second;
//     }

//     void deploy(uint64_t number) {
//         uint64_t sector_id = number / PAGE_SIZE_BITS;
//         uint64_t gadget_loc = number % PAGE_SIZE_BITS;
        
//         if (gotham_city.find(sector_id) == gotham_city.end()) {
//             gotham_city[sector_id] = new UtilityBelt();
//         }
//         gotham_city[sector_id]->gadgets[gadget_loc / 64] |= (1ULL << (gadget_loc % 64));
//     }

//     bool signal(uint64_t number) {
//         uint64_t sector_id = number / PAGE_SIZE_BITS;
//         uint64_t gadget_loc = number % PAGE_SIZE_BITS;
        
//         if (gotham_city.find(sector_id) == gotham_city.end()) return false;
//         return (gotham_city[sector_id]->gadgets[gadget_loc / 64] & (1ULL << (gadget_loc % 64))) != 0;
//     }

//     size_t wayne_tech_specs() {
//         size_t size = sizeof(*this);
//         size += gotham_city.size() * (sizeof(uint64_t) + sizeof(UtilityBelt*) + sizeof(UtilityBelt)); 
//         size += gotham_city.size() * (PAGE_SIZE_BITS / 8);
//         return size;
//     }
// };
#pragma once
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <cstring> // For memset

class BatCave {
private:
    // 64KB Page = 65536 bits.
    // Power of 2 is CRITICAL for bitwise optimization.
    static const uint64_t PAGE_SIZE_BITS = 65536; 
    static const uint64_t PAGE_MASK = PAGE_SIZE_BITS - 1; // 0xFFFF
    static const int SHIFT_AMOUNT = 16; // 2^16 = 65536

    struct UtilityBelt {
        // Optimization 1: Raw Array instead of Vector.
        // Saves 24 bytes overhead per page + avoids heap fragmentation.
        uint64_t gadgets[1024]; // 1024 * 64 bits = 65536 bits

        UtilityBelt() {
            // Zero out the memory instantly using low-level memset
            std::memset(gadgets, 0, sizeof(gadgets));
        }
    };

    std::unordered_map<uint64_t, UtilityBelt*> gotham_city;

public:
    BatCave() {}
    
    ~BatCave() {
        for (auto& pair : gotham_city) delete pair.second;
    }

    // Optimization 2: Bitwise Operations (Processor Native Speed)
    inline void deploy(uint64_t number) {
        // number / 65536  -->  number >> 16 (Instant)
        uint64_t sector_id = number >> SHIFT_AMOUNT;
        
        // number % 65536  -->  number & 0xFFFF (Instant)
        uint64_t local_index = number & PAGE_MASK;

        if (gotham_city.find(sector_id) == gotham_city.end()) {
            gotham_city[sector_id] = new UtilityBelt();
        }
        
        // local_index / 64 --> >> 6
        // local_index % 64 --> & 63
        gotham_city[sector_id]->gadgets[local_index >> 6] |= (1ULL << (local_index & 63));
    }

    // Optimization 3: Batch Processing (The Game Changer)
    // استقبلنا فيكتور كامل عشان نلف عليه بـ C++ Speed مش Python Speed
    void deploy_batch(const std::vector<uint64_t>& numbers) {
        for (uint64_t num : numbers) {
            deploy(num);
        }
    }

    bool signal(uint64_t number) {
        uint64_t sector_id = number >> SHIFT_AMOUNT;
        uint64_t local_index = number & PAGE_MASK;
        
        if (gotham_city.find(sector_id) == gotham_city.end()) return false;
        
        return (gotham_city[sector_id]->gadgets[local_index >> 6] & (1ULL << (local_index & 63))) != 0;
    }

    size_t wayne_tech_specs() {
        size_t size = sizeof(*this);
        // More accurate memory calculation for Raw Arrays
        size += gotham_city.size() * (sizeof(uint64_t) + sizeof(UtilityBelt*) + sizeof(UtilityBelt)); 
        return size;
    }
};