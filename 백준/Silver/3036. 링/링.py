import sys
from collections import defaultdict

def cal_gcd(x, y):
    if(x % y == 0):
        return y
    else:
        return cal_gcd(y, x % y)

n = int(input())
arr = list(map(int, input().split()))
x = arr[0]
for i in range(1, n):
    gcd = cal_gcd(x, arr[i])
    a = x // gcd
    b = arr[i] // gcd
    print(f"{a}/{b}")