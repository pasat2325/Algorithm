import sys
from bisect import bisect_left
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
def lower_bound(x, il, ir):
    left= il
    right = ir
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < x:
            left = mid + 1
        else:
            right = mid 
    return left

ans = 0 
for i in range(n - 2):
    curr = arr[i]
    left, right = i + 1, n - 1

    while left < right:
        s = curr + arr[left] + arr[right]

        if s == 0:
            if arr[left] == arr[right]:
                ans += right - left 
            else:
                idx = bisect_left(arr, arr[right])
                ans += right - idx + 1
            left += 1

        else:
            if s > 0 :
                right -= 1
            else:
                left += 1

print(ans)
