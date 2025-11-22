import bat_bit
import sys

print(f"Bat-Bit Module Loaded: {bat_bit}")
try:
    bruce = bat_bit.BatCave()
    bruce.deploy(100)
    if bruce.signal(100):
        print("✅ Bat-Bit Test Passed: Signal verified.")
    else:
        print("❌ Bat-Bit Test Failed: Signal not found.")
        sys.exit(1)
except Exception as e:
    print(f"❌ Bat-Bit Test Failed with error: {e}")
    sys.exit(1)
