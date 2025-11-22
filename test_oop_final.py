import time
import sys
import os

# Ensure we import the local build if needed (though pip install . should handle it)
sys.path.insert(0, os.path.abspath("python"))
import bat_bit

print("🦇 BAT-BIT OOP ENGINE: INITIALIZED")
print("="*40)
print(f"sys.path: {sys.path}")
print(f"Module file: {bat_bit.__file__}")
print(f"Module content: {dir(bat_bit)}")

try:
    # 1. Create Store and Define Schema
    store = bat_bit.BatStore()
    store.add_str_col("username")
    store.add_int_col("age")
    store.add_float_col("balance")

    print("🚀 Creating 1 Million User Objects...")
    start = time.time()

    # Simulate data loading loop
    for i in range(1000000):
        uid = store.new_row()
        store.set_str("username", uid, f"User_{i}")
        store.set_int("age", uid, 20 + (i % 50))
        store.set_float("balance", uid, i * 1.5)

    end = time.time()

    print(f"✅ Created 1M Objects in {end - start:.4f}s")
    print(f"💾 Memory Used: {store.memory_usage() / 1024 / 1024:.2f} MB")
    print("-" * 20)

    # Retrieve data to verify
    uid_check = 500
    print(f"🔍 Checking User ID {uid_check}:")
    username = store.get_str('username', uid_check)
    age = store.get_int('age', uid_check)
    balance = store.get_float('balance', uid_check)
    
    print(f"   Name: {username}")
    print(f"   Age:  {age}")
    print(f"   Bal:  {balance}")

    # Verification assertions
    if username != f"User_{uid_check}":
        print(f"❌ Error: Expected User_{uid_check}, got {username}")
        sys.exit(1)
    if age != 20 + (uid_check % 50):
        print(f"❌ Error: Expected Age {20 + (uid_check % 50)}, got {age}")
        sys.exit(1)
    if balance != uid_check * 1.5:
        print(f"❌ Error: Expected Balance {uid_check * 1.5}, got {balance}")
        sys.exit(1)

    print("\n🦇 OOP Module is fully operational.")

except Exception as e:
    print(f"\n❌ An error occurred: {e}")
    sys.exit(1)
