import sys
input = sys.stdin.readline

n,m = map(int, input().split())

queens = list(map(int, input().split()))
knights = list(map(int, input().split()))
pawns = list(map(int, input().split()))

queen_count = queens[0]
knight_count = knights[0]
pawn_count = pawns[0]

board = [[0] * (m + 1) for _ in range(n + 1)]

backslashx = [1,-1]
backslashy = [1,-1]
slashx = [1,-1]
slashy = [-1,1]
kdx = [-2,-2,-1,-1,1,1,2,2]
kdy = [-1,1,-2,2,-2,2,-1,1]

for i in range(knight_count):
    kx, ky = knights[i * 2 + 1], knights[i * 2 + 2]
    kx -= 1
    ky -= 1
    board[kx][ky] = 2
    for j in range(8):
        knx = kx + kdx[j]
        kny = ky + kdy[j]

        if knx < 0 or kny < 0 or knx >= n or kny >= m:
            continue
        if board[knx][kny] == 2:
            continue
        board[knx][kny] = 1

for i in range(pawn_count):
    px, py = pawns[i * 2 + 1], pawns[i * 2 + 2]
    px -=1
    py -=1
    board[px][py] = 2

for i in range(queen_count):
    qx, qy = queens[i * 2 + 1], queens[i * 2 + 2]
    qx -=1
    qy -=1
    board[qx][qy] = 2

    qny = qy
    # 가로 어택
    while True:
        qny -= 1
        if qny < 0:
            break
        if board[qx][qny] == 2:
            break
        board[qx][qny] = 1
    qny = qy
    while True:
        qny += 1
        if qny >= m:
            break
        if board[qx][qny] == 2:
            break
        board[qx][qny] = 1
    
    qnx = qx
    # 세로 어택
    while True:
        qnx -= 1
        if qnx < 0:
            break
        if board[qnx][qy] == 2:
            break
        board[qnx][qy] = 1
    qnx = qx
    while True:
        qnx += 1
        if qnx >= n:
            break
        if board[qnx][qy] == 2:
            break
        board[qnx][qy] = 1

    # \ 대각 어택
    unx, uny, dnx, dny = qx, qy, qx, qy
    up, down = False, False
    while True:
        if up and down:
            break

        if not down:
            dnx = dnx + backslashx[0]
            dny = dny + backslashy[0]
        
            if dnx < 0 or dny < 0 or dnx >= n or dny >= m: 
                down= True
            elif board[dnx][dny] == 2:
                down= True
            else:
                board[dnx][dny] = 1

        if not up:
            unx = unx + backslashx[1] 
            uny = uny + backslashy[1]

            if unx < 0 or uny < 0 or unx >= n or uny >= m:
                up = True
            elif board[unx][uny] == 2:
                up = True
            else:
                board[unx][uny] = 1
    
    # / 대각 어택
    unx, uny, dnx, dny = qx, qy, qx, qy
    up, down = False, False
    while True:
        if up and down:
            break
        
        if not down:
            dnx = dnx + slashx[0]
            dny = dny + slashy[0]
            if dnx < 0 or dny < 0 or dnx >= n or dny >= m: 
                down= True
            elif board[dnx][dny] == 2:
                down = True
            else:
                board[dnx][dny] = 1

        if not up:
            unx = unx + slashx[1] 
            uny = uny + slashy[1]
            if unx < 0 or uny < 0 or unx >= n or uny >= m:
                up = True
            elif board[unx][uny] == 2:
                up = True
            else:
                board[unx][uny] = 1
        
ans = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            ans += 1
print(ans)



    
        




