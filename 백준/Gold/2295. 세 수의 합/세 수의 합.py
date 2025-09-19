import sys
input = sys.stdin.readline

n = int(input())
arr = [int(input()) for _ in range(n)]
ssum = [arr[i] + arr[j] for i in range(n) for j in range(i, n)]
arr.sort()
ssum.sort()

def bs(target):
    L = 0
    R = len(ssum) - 1
    
    while(L <= R):
        mid = (L + R) // 2
        if ssum[mid] == target:
            return True
        elif ssum[mid] > target:
            R = mid - 1
        elif ssum[mid] < target:
            L = mid + 1
    return False

for i in range(n - 1, -1, -1):
    for j in range(i, -1, -1):
        m = arr[i] - arr[j]
        if bs(m):
            print(arr[i])
            quit()
