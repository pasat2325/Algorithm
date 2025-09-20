import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

arr.sort()

tmp = 0 # 각 자연수들의 대표 자연수 계산 결과값
prev = arr[0] # 대표 자연수 init
for i in range(n):
    tmp += abs(prev - arr[i])

min_tmp = tmp
ans = arr[0]
for i in range(1, n):
    x = arr[i]
    diff = x - prev
    tmp += diff * i
    tmp -= diff * (n - i)
    prev = x

    if tmp < min_tmp:
        ans = arr[i]
        min_tmp = tmp

print(ans)