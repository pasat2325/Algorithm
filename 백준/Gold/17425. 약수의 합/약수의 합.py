import sys
input = sys.stdin.readline
MAX_N = 1000001
dp = [0] * MAX_N

for i in range(1,MAX_N):
    for j in range(i, MAX_N, i):
        dp[j] += i
    dp[i] += dp[i - 1]

t = int(input())

for i in range(t):
    n = int(input())
    print(dp[n])