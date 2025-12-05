C, N = map(int, input().split())
WIFI = [int(input()) for _ in range(C)]
WIFI.sort()
max_dist = WIFI[-1] - WIFI[0]

def count_WIFI(dist):
    cnt = 1
    prev = WIFI[0]

    for x in WIFI[1:]:
        if (x - prev) >= dist:
            cnt += 1
            prev = x
    return cnt

# 거리를 매개변수로 이분탐색
def binary_search():
    left = 1
    right = max_dist

    res = 0
    while left <= right:
        mid = (left + right) // 2

        if count_WIFI(mid) >= N:
           left = mid + 1
           res = mid
        else:
            right = mid - 1 
    return res

print(binary_search())
