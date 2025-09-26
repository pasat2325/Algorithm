import sys
input = sys.stdin.readline

n,m = map(int, input().split())
M = [list(input().strip()) for i in range(n)]
visited = [False] * 26

dx = [1,-1,0,0]
dy = [0,0,1,-1]

ans = 0
def dfs(x, y, status, cnt):
    global ans
    ans = max(ans, cnt)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx >= 0 and ny >= 0 and nx < n and ny < m:
            bit = 1 << (ord(M[nx][ny]) - ord('A'))
            if not status & bit:
                dfs(nx, ny, status | bit, cnt + 1)
    
dfs(0,0,1 << (ord(M[0][0]) - ord('A')), 1)

print(ans)