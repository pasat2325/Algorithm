n,m =map(int, input().split())
r,c,d = map(int, input().split())
mp = [list(map(int, input().split())) for _ in range(n)]

# 북, 동, 남, 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

res = 0
curx = r
cury = c
curd = d
while(True):
    
    if(mp[curx][cury] == 0):
        mp[curx][cury] = 2
        res += 1

    need_clean = False    
    for _ in range(4):
        curd = (curd + 3) % 4
        nx = curx + dx[curd]
        ny = cury + dy[curd]

        if(nx >= 0 and ny >= 0 and nx < n and ny < m and mp[nx][ny] == 0):
            need_clean = True
            curx = nx
            cury = ny
            break
    
    if need_clean:
        continue

    back_dir = (curd + 2) % 4
    bx = curx + dx[back_dir]
    by = cury + dy[back_dir]

    if (bx >= 0 and by >= 0 and bx < n and by < m and mp[bx][by] == 1):
        break
    
    curx = bx
    cury = by

print(res)

