def binary_search(arr, x, end, start = 0, ):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == x:
            return 1
        elif arr[mid] > x:
            end = mid - 1
        elif arr[mid] < x:
            start = mid + 1
    return 0

while 1:
    n, m = map(int, input().split())
    if not n and not m:
        break
    
    A = []
    
    for _ in range(n):
        x = int(input())
        A.append(x)

    A.sort()
    cnt = 0
    for _ in range(m):
        x = int(input())
        cnt += binary_search(A, x, len(A) - 1, 0)
    
    print(cnt)