from collections import deque

n,m = map(int, input().split())
grid = []
visited = [[False] * m for _ in range(n)]

q = deque()
dx = [1,-1,0,0]
dy = [0,0,1,-1]


def bfs(x, y, d):
    visited[x][y] = True
    q.append((x,y,d))

    while q:
        cx, cy, cd = q.popleft()
        
        if cx == n - 1 and cy == m - 1:
            return cd
        
        for i in range (4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            
            if grid[nx][ny] == 0:
                continue

            if visited[nx][ny]:
                continue
            
            visited[nx][ny] = True
            q.append((nx, ny, cd + 1))



for i in range(n):
    row = list(map(int,input().rstrip()))
    grid.append(row)

res =bfs(0,0,1)
print(res)

