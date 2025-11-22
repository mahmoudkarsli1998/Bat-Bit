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
#pragma once
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <string>
#include <cstring> // For memset
#include <stdexcept> // For exceptions

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

// ==========================================
// 2. New: BatVector (Python List Alternative)
// ==========================================
class BatVector {
private:
    std::vector<uint64_t> data;

public:
    BatVector() { data.reserve(1000); } // Initial reservation for speed

    void push(uint64_t val) {
        data.push_back(val);
    }

    // Batch Insert (Hypersonic)
    void push_batch(const std::vector<uint64_t>& chunk) {
        data.insert(data.end(), chunk.begin(), chunk.end());
    }

    uint64_t get(size_t index) {
        if (index >= data.size()) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    void set(size_t index, uint64_t val) {
        if (index >= data.size()) throw std::out_of_range("Index out of bounds");
        data[index] = val;
    }

    size_t size() { return data.size(); }

    size_t memory_usage() {
        return data.capacity() * sizeof(uint64_t);
    }
};

// ==========================================
// 3. New: BatMap (Python Dictionary Alternative)
// ==========================================
class BatMap {
private:
    // Map linking ID (int) to Score (double)
    // Python consumes a lot of memory storing Types, here we are typed
    std::unordered_map<uint64_t, double> map;

public:
    void put(uint64_t key, double value) {
        map[key] = value;
    }

    void put_batch(const std::vector<uint64_t>& keys, const std::vector<double>& values) {
        if (keys.size() != values.size()) throw std::runtime_error("Keys and Values size mismatch");
        for (size_t i = 0; i < keys.size(); ++i) {
            map[keys[i]] = values[i];
        }
    }

    double get(uint64_t key) {
        if (map.find(key) == map.end()) return -1.0; // Default value
        return map[key];
    }

    bool contains(uint64_t key) {
        return map.find(key) != map.end();
    }

    size_t memory_usage() {
        return map.size() * (sizeof(uint64_t) + sizeof(double) + 16); 
    }
};

// ==========================================
// 4. The OOP Engine: BatStore (Columnar DB)
// ==========================================
class BatStore {
private:
    // Column Stores: Each data type has its own store
    // This keeps memory contiguous and very fast for search
    std::unordered_map<std::string, std::vector<int64_t>> int_cols;
    std::unordered_map<std::string, std::vector<double>> float_cols;
    std::unordered_map<std::string, std::vector<std::string>> string_cols;
    
    uint64_t row_count = 0;

public:
    // 1. Schema Definition
    void add_int_col(std::string name) { int_cols[name] = std::vector<int64_t>(); }
    void add_float_col(std::string name) { float_cols[name] = std::vector<double>(); }
    void add_str_col(std::string name) { string_cols[name] = std::vector<std::string>(); }

    // 2. Create Object ID (New Row)
    uint64_t new_row() {
        uint64_t id = row_count++;
        // Lazy Expansion: Resize columns to accommodate new row
        // Note: We reserve space, not fill data yet
        for (auto& [k, v] : int_cols) if (v.size() <= id) v.resize(id + 1, 0);
        for (auto& [k, v] : float_cols) if (v.size() <= id) v.resize(id + 1, 0.0);
        for (auto& [k, v] : string_cols) if (v.size() <= id) v.resize(id + 1, "");
        return id;
    }

    // 3. Setters
    void set_int(std::string col, uint64_t id, int64_t val) { 
        if (int_cols.find(col) != int_cols.end()) int_cols[col][id] = val; 
    }
    void set_float(std::string col, uint64_t id, double val) { 
        if (float_cols.find(col) != float_cols.end()) float_cols[col][id] = val; 
    }
    void set_str(std::string col, uint64_t id, std::string val) { 
        if (string_cols.find(col) != string_cols.end()) string_cols[col][id] = val; 
    }

    // 4. Getters
    int64_t get_int(std::string col, uint64_t id) { return int_cols[col][id]; }
    double get_float(std::string col, uint64_t id) { return float_cols[col][id]; }
    std::string get_str(std::string col, uint64_t id) { return string_cols[col][id]; }

    // Memory Usage Calculation
    size_t memory_usage() {
        size_t size = 0;
        for (auto& [k, v] : int_cols) size += v.capacity() * sizeof(int64_t);
        for (auto& [k, v] : float_cols) size += v.capacity() * sizeof(double);
        for (auto& [k, v] : string_cols) {
            size += v.capacity() * sizeof(std::string);
            for (const auto& s : v) size += s.capacity(); // Actual string size
        }
        return size;
    }
};