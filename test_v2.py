import sys
import os
import time

# Add 'python' directory to sys.path to find the extension
# Assuming we run from project root
sys.path.insert(0, os.path.abspath("python"))

import bat_bit
print("="*40)
print(f"Module file: {bat_bit.__file__}")
print(f"Module content: {dir(bat_bit)}")

try:
    # --- 1. Testing BatVector ---
    print("\n📏 Testing BatVector (High Speed Array)...")
    vec = bat_bit.BatVector()

    # Python List vs BatVector
    start = time.time()
    data = list(range(5000000)) # 5 Million items
    vec.push_batch(data)
    print(f"✅ Pushed 5 Million items in {time.time() - start:.4f}s")
    print(f"💾 Memory: {vec.memory_usage() / 1024 / 1024:.2f} MB")
    print(f"🔍 Access Item [100]: {vec[100]}")
    
    # Verify content
    if vec[100] != 100:
        print("❌ Error: vec[100] should be 100")
        sys.exit(1)

    # --- 2. Testing BatMap ---
    print("\n🗺️ Testing BatMap (Typed Dictionary)...")
    m = bat_bit.BatMap()

    # Batch Insert Map
    keys = [i for i in range(1000000)]
    values = [i * 1.5 for i in range(1000000)]

    start = time.time()
    m.put_batch(keys, values)
    print(f"✅ Mapped 1 Million items in {time.time() - start:.4f}s")
    print(f"💾 Memory: {m.memory_usage() / 1024 / 1024:.2f} MB")
    print(f"🔍 Get Key [500]: {m[500]}")
    
    # Verify content
    if m[500] != 500 * 1.5:
        print("❌ Error: m[500] should be 750.0")
        sys.exit(1)

    print("\n🦇 All Systems Operational.")

except Exception as e:
    print(f"\n❌ An error occurred: {e}")
    sys.exit(1)
