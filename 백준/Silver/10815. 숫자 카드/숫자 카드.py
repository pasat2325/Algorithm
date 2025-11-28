n = int(input())
A = list(map(int, input().split()))

m = int(input())
B = list(map(int, input().split()))

def binary_search(x):
    start = 0
    end = len(A) - 1

    while start <= end:
        mid = (start + end) // 2
        if A[mid] == x:
            return 1
        elif A[mid] > x:
            end = mid -1
        elif A[mid] < x:
            start = mid + 1
    
    return 0

A.sort()
for v in B:
    print(binary_search(v), end =' ')