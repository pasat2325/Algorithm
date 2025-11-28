import sys
input = sys.stdin.readline

n, m = map(int,input().split())
heights = list(map(int,input().split()))
h_max_height = max(heights) - 1

# 절단기 높이가 h일 때 가져가는 나무의 길이
def cutting(ch):
    res = 0
    for h in heights:
        if h <= ch:
            continue
        
        res += h - ch
    return res

def binary_search(mh):
    left = 0
    right = h_max_height

    res = 0

    while left <= right:
        mid = (left + right) // 2

        # 가져가는 나무 길이가 최소 길이보다 길다면 절단기 높이를 더 높게  
        if cutting(mid) >= mh: 
            left = mid + 1
            res = mid
        # 가져가는 나무 길이가 최소 길이보다 짧다면 절단기 높이를 더 낮게
        else:
            right = mid - 1
    return res

ans = binary_search(m)
print(ans)
        