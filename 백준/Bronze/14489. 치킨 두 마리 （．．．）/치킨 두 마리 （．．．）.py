import sys

n,m = map(int, input().split())
k = int(input())

if n + m >= k * 2:
    print((n + m)- k * 2) 
else:
     print(n+m)