import sys
n,m =map(int, input().split())
r,c,d = map(int, input().split())
mp = [list(map(int, input().split())) for _ in range(n)]

# 북, 동, 남, 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

res = 0
def solve(x, y, d):
    global res
    if mp[x][y] == 0:
        mp[x][y] = 2
        res += 1
    
    for _ in range(4):
        d = (d + 3) % 4
        nx = x + dx[d]
        ny = y + dy[d]
        if nx >= 0 and ny >= 0 and nx < n and ny < m and mp[nx][ny] == 0:
            solve(nx, ny, d)
            return
    
    nx = x - dx[d]
    ny = y - dy[d]
    if nx >=0 and ny >= 0 and nx < n and ny < m and mp[nx][ny] != 1:
        solve(nx, ny, d)

solve(r,c,d)
print(res)

