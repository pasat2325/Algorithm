import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

A.sort()

# x 이상인 값이 처음나오는 인덱스 찾기
def lower_bound(x):
    start = 0
    end = len(A)

    while start < end:
        mid = (start + end) // 2

        if A[mid] < x:
            start = mid + 1
        elif A[mid] >= x:
            end = mid

    return start

# x 초과하는 값이 처음 나오는 인덱스 찾기
def upper_bound(x):
    start = 0
    end = len(A)

    while start < end:
        mid = (start + end) // 2

        if A[mid] <= x:
            start = mid + 1
        elif A[mid] > x:
            end = mid
    return start

result = []
for v in B:
    cnt = str(upper_bound(v) - lower_bound(v))
    result.append(cnt)

print(" ".join(result))