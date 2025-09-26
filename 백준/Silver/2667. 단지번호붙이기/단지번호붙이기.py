import sys
input = sys.stdin.readline

n = int(input())
grid = [list(map(int, input().strip()))for _ in range(n)]


visited = [ [False for j in range(n)] for i in range(n)]
dx = [1,-1,0,0]
dy = [0,0,1,-1]

cnt = 0
def dfs(x, y):
    global cnt
    visited[x][y] = True
    cnt += 1

    for i in range(4):
        nextx = x + dx[i]
        nexty = y + dy[i]

        if nextx < 0 or nexty < 0 or nextx >= n or nexty >= n or grid[nextx][nexty] == 0 or visited[nextx][nexty] == True:
            continue
        
        dfs(nextx, nexty)
    
    return

cnts = []
for i in range(n):
    for j in range(n):
        cnt = 0
        if grid[i][j] == 0 or visited[i][j] == True:
            continue
        dfs(i,j)
        cnts.append(cnt)

cnts.sort()
print(len(cnts))
for c in cnts:
    print(c)
