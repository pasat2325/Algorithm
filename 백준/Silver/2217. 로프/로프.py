n = int(input())
arr = []

for _ in range(n):
    x = int(input())
    arr.append(-x)

arr.sort()

ans = 0
for i in range(1, n + 1):
    cur = -arr[i - 1]
    ans = max(ans, cur * i)

print(ans)