import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))
okn = [-1] * (n)
stack = []

for i, val in enumerate(arr):
    while stack and val > stack[-1][0]:
        top_val, idx = stack.pop()
        okn[idx] = val
    stack.append((val, i))

print(*okn)

