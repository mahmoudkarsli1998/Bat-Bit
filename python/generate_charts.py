import os

def create_bar_chart(filename, title, labels, values, colors, unit):
    width = 600
    height = 400
    bar_height = 50
    start_y = 100
    max_val = max(values)
    
    svg = f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" style="background-color: #0d1117; font-family: sans-serif;">'
    svg += f'<text x="300" y="40" text-anchor="middle" fill="white" font-size="24" font-weight="bold">{title}</text>'
    
    for i, (label, value, color) in enumerate(zip(labels, values, colors)):
        y = start_y + i * 100
        bar_width = (value / max_val) * 400
        
        # Label
        svg += f'<text x="20" y="{y + bar_height/2 + 5}" fill="white" font-size="16">{label}</text>'
        
        # Bar
        svg += f'<rect x="150" y="{y}" width="{bar_width}" height="{bar_height}" fill="{color}" rx="5" />'
        
        # Value
        svg += f'<text x="{150 + bar_width + 10}" y="{y + bar_height/2 + 5}" fill="white" font-size="14">{value:,} {unit}</text>'

    svg += '</svg>'
    
    with open(filename, "w", encoding="utf-8") as f:
        f.write(svg)
    print(f"Generated {filename}")

# Memory Comparison (Lower is better)
# Note: For visual representation, we invert the bar logic or just show raw size. 
# Let's show raw size.
create_bar_chart(
    "memory_comparison.svg", 
    "Memory Usage (10M Integers)", 
    ["Python Set", "Bat-Bit 🦇"], 
    [600, 120], 
    ["#e74c3c", "#2ecc71"], 
    "MB"
)

# Speed Comparison (Higher is better)
# Python Set: ~5s for 10M (approx 2M ops/sec)
# Bat-Bit: ~1.3s for 10M (approx 7.2M ops/sec)
create_bar_chart(
    "speed_comparison.svg", 
    "Insertion Speed (Ops/Sec)", 
    ["Python Set", "Bat-Bit 🦇"], 
    [2000000, 7253170], 
    ["#95a5a6", "#f1c40f"], 
    "ops/sec"
)
