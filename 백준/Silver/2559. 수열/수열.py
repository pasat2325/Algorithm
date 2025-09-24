import sys
input = sys.stdin.readline
n, k =map(int, input().split())
arr = list(map(int, input().split()))

val = 0
for i in range(k):
    val += arr[i]

ans = val
for i in range(k, n):
    val += arr[i]
    val -= arr[i - k]
    ans = max(ans, val)

print(ans)