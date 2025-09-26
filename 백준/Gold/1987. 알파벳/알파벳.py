def solve():
    H, W = map(int, input().split())
    board = [input().strip() for _ in range(H)]
    DIRS = [(-1,0),(1,0),(0,-1),(0,1)]

    start_mask = 1 << (ord(board[0][0]) - 65)
    stack = [(0, 0, start_mask, 1)]
    seen = {(0, 0, start_mask)} 
    ans = 1

    while stack:
        y, x, mask, d = stack.pop()
        if d > ans:
            ans = d
            if ans == 26: break
        for dy, dx in DIRS:
            ny, nx = y + dy, x + dx
            if 0 <= ny < H and 0 <= nx < W:
                bit = 1 << (ord(board[ny][nx]) - 65)
                if mask & bit:  # 이미 쓴 알파벳
                    continue
                state = (ny, nx, mask | bit)
                if state in seen:
                    continue
                seen.add(state)
                stack.append((ny, nx, mask | bit, d + 1))
    print(ans)

solve()