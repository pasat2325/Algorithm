import sys
input = sys.stdin.readline

n = int(input())
grid = [list(map(int, input().strip())) for _ in range(n)]
visited = [[False for j in range(n)] for i in range(n)]
dx = [1,-1,0,0]
dy = [0, 0, 1, -1]

cnt = 0
def dfs(x, y):
    visited[x][y] = True
    global cnt
    cnt += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= n or grid[nx][ny] == 0 or visited[nx][ny] == True:
            continue
        
        dfs(nx, ny)

cnts = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 0 or visited[i][j] == True:
            continue
        cnt = 0
        dfs(i, j)
        cnts.append(cnt)

cnts.sort()
print(len(cnts))
for c in cnts:
    print(c)