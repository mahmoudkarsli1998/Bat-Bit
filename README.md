# 🦇 Bat-Bit Engine

> **"It's not who I am underneath, but what I do that defines me."**
> *The fastest, most memory-efficient Bitset Engine for Python.*

[![License: MIT](https://img.shields.io/badge/License-MIT-black.svg)](https://opensource.org/licenses/MIT)

## 🌃 The Problem
Storing **10 Million integers** in a standard Python `set` consumes **~600 MB of RAM**.

## 🦇 The Solution
**Bat-Bit** is a C++ engine using **Sparse Paging**. It only allocates memory for numbers that exist.
* **Speed:** O(1) Instant Lookup.
* **Memory:** ~120 MB (80% Savings).

## ⚡ Benchmarks

| Metric | Python `set()` | **Bat-Bit** 🦇 |
| :--- | :--- | :--- |
| **Memory (10M Items)** | ~600 MB | **~119 MB** |
| **Lookup Speed** | Fast | **Instant** |

## 🛠 Installation

```bash
pip install .
💻 Usage
Python

import bat_bit

bruce = bat_bit.BatCave()
bruce.deploy(1000000000) # Insert 1 Billion

if bruce.signal(1000000000):
    print("Found!")

**You are done!** You have built a C++ Extension, compiled it on Windows, linked it to Python, and published it. You are now an Open Source Tool Creator. 🦇🔥