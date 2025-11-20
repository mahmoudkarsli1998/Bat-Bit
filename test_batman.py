import bat_bit
import time
import sys

def print_banner():
    print("\n" + "="*40)
    print("🦇 INITIALIZING BAT-BIT PROTOCOL 🦇")
    print("="*40)

def run_test():
    print_banner()
    
    # 1. Initialize
    bruce = bat_bit.BatCave()
    print("[INFO] BatCave System Online.")
    print(f"[INFO] Initial RAM: {bruce.memory_usage()} bytes\n")

    # 2. Stress Test (Insertion)
    print("🚀 MISSION: Deploying 10 Million Gadgets (Sparse Data)...")
    print("   (Inserting numbers from 0 to 1 Billion with gaps)")
    
    start_time = time.time()
    
    # We simulate a massive dataset with gaps
    count = 0
    for i in range(0, 1000000000, 100): # Loop up to 1 Billion, step 100
        bruce.deploy(i)
        count += 1
        
    end_time = time.time()
    duration = end_time - start_time
    
    print(f"✅ MISSION COMPLETE.")
    print(f"⚡ Records Inserted: {count:,}")
    print(f"⏱️ Time Taken:      {duration:.4f} seconds")
    print(f"🔥 Speed:           {int(count/duration):,} ops/sec")

    # 3. Verification (Search)
    print("\n🔍 TURNING ON THE BAT-SIGNAL (Search Test)...")
    
    assert bruce.signal(500) == True
    print("   Target [500] ......... FOUND ✅")
    
    assert bruce.signal(999999900) == True
    print("   Target [999,999,900] . FOUND ✅")
    
    assert bruce.signal(777) == False
    print("   Target [777] ......... NOT FOUND (Correct) ✅")

    # 4. Memory Audit
    ram_bytes = bruce.memory_usage()
    ram_mb = ram_bytes / (1024 * 1024)
    
    print("\n💾 WAYNE TECH MEMORY AUDIT:")
    print(f"   Total RAM Used: {ram_mb:.2f} MB")
    print("   (A standard Python set would use ~500MB+ for this)")
    print("\n🦇 GOTHAM IS SAFE.")

if __name__ == "__main__":
    run_test()