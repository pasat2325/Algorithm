import sys
input = sys.stdin.readline
n = int(input())
arr = [int(input()) for _ in range(n)]
arr_set = set([arr[i] + arr[j] for i in range(n) for j in range(i, n)])

arr.sort()

for i in range(n-1, -1, -1):
    for j in range(i, -1, -1):
        if(arr[i] - arr[j] in arr_set):
            print(arr[i])
            sys.exit(0)
