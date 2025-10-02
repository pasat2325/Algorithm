import sys
input = sys.stdin.readline

n,k = map(int,input().split())
str = input()
check = [False] * n
ans = 0
for i in range(n):
    if str[i] == 'P':
        front = max(0, i - k)
        rear = min(n, i + k + 1)
        for j in range(front, rear):
            if(str[j] == 'H' and check[j] == False):
                check[j] = True
                ans += 1
                break

print(ans)
