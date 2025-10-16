import sys
input = sys.stdin.readline
r,c = map(int, input().split())
grid = [list(input().rstrip()) for i in range(r)]



dx = [1,-1,0,0]
dy = [0,0,1,-1]

def cd(i, j):
  cnt = 0
  for v in range(4):
    nx = i + dx[v]
    ny = j + dy[v]
    
    if nx < 0 or ny < 0 or nx >= r or ny >= c:
      cnt += 1
      continue

    if grid[nx][ny] == '.':
      cnt += 1
  
  if cnt >= 3:
    return True
  return False

for i in range(r):
  for j in range(c):
    if(grid[i][j] == 'X'):
      re = cd(i,j)
      if re:
        grid[i][j] = 'E'

minrow = 1000
maxrow = -1
minidx = 1000
maxidx = -1
for i in range(r):
  for j in range(c):
    if grid[i][j] == 'X':
      minrow = min(minrow, i)
      maxrow = max(maxrow, i)
      minidx = min(minidx, j)
      maxidx = max(maxidx, j)
    elif grid[i][j] == 'E':
      grid[i][j] = '.'

for i in range(minrow, maxrow + 1):
  for j in range(minidx, maxidx + 1):
    print(grid[i][j] ,end  = '')
  print()