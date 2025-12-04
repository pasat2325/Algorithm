import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    x, y = map(int, input().split())
    arr.append((x, y))

arr.sort()


start = -int(1e31) - 1
end = -int(1e31) - 1
ans = 0
for tup in arr:
    x = tup[0]
    y = tup[1]

    # new line started
    if x > end:
        ans += end - start
        start = x
        end = y
        
    
    else:
        end = max(y, end)

ans += end - start

print(ans)
