import sys
t = int(input())

while(t):
    t -= 1
    line = input() # empty line
    
    r,c = map(int,input().split())
    grid = [list(input()) for _ in range(r)]
    visited = [[False]* c for _ in range(r)]

    cand = 0
    for i in range(r):
        for j in range(c):
            if visited[i][j]:
                continue

            if grid[i][j] == '.':
                visited[i][j] = True
                continue
            elif grid[i][j] == 'o':
                visited[i][j] = True
                continue
            elif grid[i][j] == '>':
                if j + 2 < c and grid[i][j + 1] == 'o' and grid[i][j + 2] == '<':
                    cand += 1
                    for k in range(3):
                        visited[i][j + k] = True
                else:
                    visited[i][j] = True

            elif grid[i][j] == 'v':
                if i + 2 < r and grid[i + 1][j] == 'o' and grid[i + 2][j] == '^':
                    cand += 1
                    for k in range(3):
                        visited[i + k][j] = True
                else:
                    visited[i][j] = True

    print(cand)