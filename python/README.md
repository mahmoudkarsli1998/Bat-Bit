# 🦇 Bat-Bit: The Dark Knight of Data Structures

> **"It's not who I am underneath, but what I do that defines me."**
> *High-Performance C++ Sparse Bitset Engine for Python.*

[![PyPI version](https://img.shields.io/pypi/v/bat-bit.svg)](https://pypi.org/project/bat-bit/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Buy Me A Coffee](https://img.shields.io/badge/Buy%20Me%20A%20Coffee-Donate-orange.svg)](https://www.buymeacoffee.com/MahmoudKarsli)

---

## 🌃 The Problem
Python's built-in `set()` and `list` are powerful, but they are memory-hungry.
Trying to store **10 Million integers** in a Python set can consume **over 600 MB of RAM**. If you work with Big Data, High-Frequency Trading, or massive IoT logs, you will hit `MemoryError` fast.

## 🦇 The Solution
**Bat-Bit** is a blazing fast C++ extension wrapped for Python. It uses **Sparse Paging Bitset** architecture to store data.
* It allocates memory *only* when needed (Sparse).
* It performs operations at the **Bit-level** (Processor friendly).
* It releases the GIL (Global Interpreter Lock) for **True Multi-Core Parallelism**.

---

## ⚡ Benchmarks (The Shocking Truth)
Tested on **10 Million Records** (Integers):

| Metric | Standard Python `set()` | **Bat-Bit** 🦇 | Improvement |
| :--- | :--- | :--- | :--- |
| **Memory Usage** | ~600 MB | **~120 MB** | **80% RAM Savings** 💾 |
| **Insertion Time** | ~12.0s | **~1.2s** | **10x Faster** 🚀 |
| **Ops / Second** | ~800k | **7.7 Million** | **Hypersonic Speed** 🔥 |

---

## 🛠 Installation

Get it directly from PyPI:

```bash
pip install bat-bit
```
Requires: Python 3.7+

## 💻 Usage

### 1. Basic Usage (Like a Set)
```python
import bat_bit

# Initialize the BatCave
bruce = bat_bit.BatCave()

# Deploy single gadget (Insert number)
bruce.deploy(500)
bruce.deploy(1000000000) # Handles massive gaps effortlessly!

# Signal check (Search / Lookup) - O(1) Time Complexity
if bruce.signal(500):
    print("Target Found!") # Prints: Target Found!

if not bruce.signal(999):
    print("Target Not Found!")
```

### 2. 🆕 New in v1.2.0: Arrays & Maps
Bat-Bit now replaces Python Lists and Dictionaries with high-performance C++ alternatives.

#### 📏 BatVector (The Fast Array)
A contiguous memory array for high-speed numeric processing.
```python
import bat_bit

# Create Vector
vec = bat_bit.BatVector()

# Batch Push (Hypersonic Speed)
data = list(range(1000000))
vec.push_batch(data)

# Access (O(1))
print(vec[500]) 
```

#### 🗺️ BatMap (The Efficient Dictionary)
A typed hash map that avoids Python object overhead.

```python
m = bat_bit.BatMap()

# Batch Insert
keys = [1, 2, 3]
values = [10.5, 20.5, 30.5]
m.put_batch(keys, values)

print(m[1]) # Output: 10.5
```

### 3. High-Speed Batch Processing
Avoid Python overhead by sending data in bulk.

```python
data = [x for x in range(1000000)] # 1 Million items
bruce.deploy_batch(data) # Super Fast
```

### 4. 🚀 Hypersonic Parallel Mode (Multi-Core)
Unleash the full power of your CPU. This method releases the GIL and uses all available CPU cores to insert data in parallel.

```python
import bat_bit
import random

# Generate 10 Million numbers
data_stream = [random.randint(0, 1000000000) for _ in range(10000000)]

bruce = bat_bit.BatCave()

# Fires on ALL Cores (e.g., 8 Threads)
bruce.deploy_batch_parallel(data_stream)

print(f"Memory Used: {bruce.memory_usage() / 1024 / 1024:.2f} MB")
```

## 🧠 How it Works
Unlike a Hash Map that stores the number itself (32/64 bits) + pointers + overhead, Bat-Bit treats memory as a Bit-Map.

The number 5 is just the 5th bit in a page set to 1.

Sparse Paging: If you store numbers 1 and 1,000,000,000, Bat-Bit only creates 2 tiny pages of memory. The empty space in between takes 0 RAM.

### 5. 🏛️ BatStore (OOP / Entity Component System)
Store millions of Objects (like Users, Products) with 80% less RAM using Columnar Storage.

```python
# Define Schema once
store = bat_bit.BatStore()
store.add_str_col("username")
store.add_int_col("age")
store.add_float_col("balance")

# Create Rows (Objects)
uid = store.new_row()
store.set_str("username", uid, "Bruce Wayne")
store.set_int("age", uid, 35)
store.set_float("balance", uid, 999999.99)

# Retrieve Data
print(store.get_str("username", uid)) # Output: Bruce Wayne
```

**Memory Benchmark (1 Million Objects):**
* **Python List of Dicts**: ~280 MB
* **BatStore**: ~62 MB (**Huge Savings!**)

## 🤝 Contributing
We welcome fellow vigilantes!

1. Fork the repo.
2. Create your feature branch (`git checkout -b feature/NewGadget`).
3. Commit your changes.
4. Push to the branch.
5. Open a Pull Request.

## 📜 License
Distributed under the MIT License. See LICENSE for more information.

Built with 🖤 using C++ & Pybind11
