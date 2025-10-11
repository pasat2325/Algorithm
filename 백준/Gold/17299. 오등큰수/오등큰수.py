import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))

freq = Counter(arr) # 각 숫자의 등장 횟수
odkn = [-1] * (n)
stack = []

for i in range(n):
    while stack and freq[arr[stack[-1]]] < freq[arr[i]]:
        odkn[stack.pop()] = arr[i]
    stack.append(i)

print(*odkn)

