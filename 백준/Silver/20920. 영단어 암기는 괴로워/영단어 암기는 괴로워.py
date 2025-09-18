import sys
from collections import defaultdict
input = sys.stdin.readline

n, m = map(int, input().split())
d = defaultdict(int)

for _ in range(n):
    s = input().rstrip()
    if len(s) < m:
        continue

    d[s] += 1

sd = sorted(d.items(), key = lambda x: (-x[1], -len(x[0]), x[0]))

for ch in sd:
    print(ch[0])