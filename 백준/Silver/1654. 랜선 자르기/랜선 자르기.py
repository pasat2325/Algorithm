import sys
input = sys.stdin.readline

n, m = map(int,input().split())
lans = []

for _ in range(n):
    x = int(input())
    lans.append(x)

max_length = max(lans)

# 랜선을 x 단위로 자를 때 몇 개의 랜선을 얻을 수 있는가?
def lan_count(x):
    cnt = 0
    
    for l in lans:
        cnt += l // x
    return cnt

def binary_search():
    left = 1
    right = max_length
    res = 0

    while left <= right:
        mid = (left + right) // 2

        if lan_count(mid) < m:
            right = mid - 1
        elif lan_count(mid) >= m:
            left = mid + 1
            res = mid
    return res

print(binary_search())