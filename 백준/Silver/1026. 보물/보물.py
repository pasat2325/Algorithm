n = int(input())
arr = list(map(int,input().split()))
brr = list(map(int,input().split()))

arr.sort()
brr.sort(reverse=True)

s = 0
for i in range(n):
    s += arr[i] * brr[i]
print(s)

