import bat_bit
import time
import random

print("\nBAT-BIT: MULTI-CORE PROTOCOL")
print("="*40)

# تجهيز البيانات (10 مليون رقم عشوائي)
print("🎲 Generating 10 Million random numbers (Python Side)...")
# بنعمل list كبيرة عشان نبعتها مرة واحدة
data_stream = [random.randint(0, 1000000000) for _ in range(10000000)] 

engine = bat_bit.BatCave()

print("\n� FIRING HYPERSONIC BATCH DEPLOYMENT...")
start = time.time()

# الضربة القاضية: بنبعت الـ 10 مليون كلهم في سطر واحد
engine.deploy_batch(data_stream)

end = time.time()
duration = end - start

print(f"✅ DONE.")
print(f"⏱️ Time Taken: {duration:.4f} seconds")
ops_sec = 10_000_000 / duration
print(f"🔥 Speed:      {int(ops_sec):,} ops/sec")

print(f"\n💾 Memory Usage: {engine.memory_usage() / 1024 / 1024:.2f} MB")

# Verification
print("\n🔍 Random Integrity Check...")
print(f"Check First Item: {engine.signal(data_stream[0])}")
print(f"Check Last Item:  {engine.signal(data_stream[-1])}")