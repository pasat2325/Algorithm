import sys
input = sys.stdin.readline

n,m = map(int, input().split())
M = [list(input().strip()) for i in range(n)]
visited = [False] * 26

dx = [1,-1,0,0]
dy = [0,0,1,-1]

ans = 0
def dfs(x, y, cnt):
    global ans
    ans = max(ans, cnt)

    idx = ord(M[x][y]) - ord('A')
    visited[idx] = True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx < 0 or ny < 0 or nx >= n or ny >= m or visited[ord(M[nx][ny]) - ord('A')]:
            continue

        dfs(nx, ny, cnt + 1)
    
    visited[idx] = False
    

dfs(0,0,1)

print(ans)