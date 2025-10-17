import sys
from collections import defaultdict

trees = defaultdict(int)
total = 0

for line in sys.stdin:
    name = line.rstrip()
    trees[name] += 1
    total += 1

for name in sorted(trees.keys()):
    freq = trees[name] / total * 100
    print(f"{name} {freq:.4f}")