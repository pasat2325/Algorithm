"""
토네이도의 시작 위치 (N // 2, N // 2)
토네이도는 한 번에 한 칸씩 이동하며, 이동 규칙은 아래와 같다.
1, 1, 2, 2, 3, 3, 4, 4 ... (N - 1), (N - 1), (N - 1) 의 거리만큼을 일적선으로 이동하고 방향을 회전한다.

방향을 회전하는 횟수는 2 * N - 1 회다.

방향 순서는 left -> down -> right -> up -> left 로 반복된다.
left ~ up = 0 ~ 3 이라고 할 때

dx = [0,1,0,-1]
dy = [-1,0,1,0]

이고, %4 를 통해 반복한다.


"""

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

lst = []
for i in range(1,n):
    for _ in range(2):
        lst.append(i)
lst.append(n - 1)

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
# 왼쪽
lbx = [-1, -1, -1, -2,  1,  1,  1,  2, 0, 0]
lby = [-1,  0,  1,  0, -1,  0,  1,  0,-2,-1]
# i: 0~7 -> 10%,7%,1%,2% (좌/우 쌍), 8 -> 5%, 9 -> 알파

dbx = [ 1,  0, -1,  0,  1,  0, -1,  0, 2, 1]
dby = [-1, -1, -1, -2,  1,  1,  1,  2, 0, 0]
rbx = [ 1,  1,  1,  2, -1, -1, -1, -2, 0, 0]
rby = [ 1,  0, -1,  0,  1,  0, -1,  0, 2, 1]
ubx = [-1,  0,  1,  0, -1,  0,  1,  0, -2, -1]
uby = [ 1,  1,  1,  2, -1, -1, -1, -2,  0,  0]

bx_all = [lbx, dbx, rbx, ubx]
by_all = [lby, dby, rby, uby]

ans = 0


def blast(x, y, d):
    global ans
    total_blow_sand = 0
    bx = bx_all[d]
    by = by_all[d]

    for i in range(10):
        nx = x + bx[i]
        ny = y + by[i]

        if i < 8 and i % 4 == 0:
            blow_sand = int(grid[x][y] * 0.1)
            total_blow_sand += blow_sand

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += blow_sand
            else:
                grid[nx][ny] += blow_sand

        elif i < 8 and i % 4 == 1:
            blow_sand = int(grid[x][y] * 0.07)
            total_blow_sand += blow_sand

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += blow_sand
            else:
                grid[nx][ny] += blow_sand

        elif i < 8 and i % 4 == 2:
            blow_sand = int(grid[x][y] * 0.01)
            total_blow_sand += blow_sand

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += blow_sand
            else:
                grid[nx][ny] += blow_sand

        elif i < 8 and i % 4 == 3:
            blow_sand = int(grid[x][y] * 0.02)
            total_blow_sand += blow_sand

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += blow_sand
            else:
                grid[nx][ny] += blow_sand

        elif i == 8:
            blow_sand = int(grid[x][y] * 0.05)
            total_blow_sand += blow_sand

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += blow_sand
            else:
                grid[nx][ny] += blow_sand

        elif i == 9:
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                ans += grid[x][y] - total_blow_sand
            else:
                grid[nx][ny] += grid[x][y] - total_blow_sand

    grid[x][y] = 0


nx = n // 2
ny = n // 2

def print_grid():
    for i in range(n):
        for j in range(n):
            print(grid[i][j], end = ' ')
        print()

for idx, val in enumerate(lst):
    cur_direction = idx % 4
    cur_distance = val

    for _ in range(cur_distance):
        nx = nx + dx[cur_direction]
        ny = ny + dy[cur_direction]

        #print()
        blast(nx, ny, cur_direction)
        #print_grid()

print(ans)

