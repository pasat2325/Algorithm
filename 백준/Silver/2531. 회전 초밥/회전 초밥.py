import sys
n,d,k,cou = map(int, input().split())
c = [0] * (d + 1)
sushi = [int(input()) for _ in range(n)]

cnt = 0
for i in range(k):
    s = sushi[i]
    if(c[s] == 0):
        cnt += 1
    c[s] += 1

ans = cnt + (1 if c[cou] == 0 else 0)
for i in range(1, n):
    rear = (i + k - 1) % n
    sub = sushi[i - 1]
    add = sushi[rear]

    c[sub] -= 1
    if c[sub] == 0:
        cnt -= 1
    
    if c[add] == 0:
        cnt += 1
    c[add] += 1

    cur = cnt + (1 if c[cou] == 0 else 0)
    if cur > ans:
        ans = cur

print(ans)