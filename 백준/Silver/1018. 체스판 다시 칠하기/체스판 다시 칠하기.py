def repaint(x, y):
    cnt_start_w = 0
    for i in range(x ,x + 8):
        for j in range(y, y + 8):
            expected = 'W' if (i + j) % 2 == 0 else 'B'
            if grid[i][j] != expected:
                cnt_start_w += 1
    
    cnt_start_b = 64 - cnt_start_w
    return min(cnt_start_w, cnt_start_b)

n, m = map(int, input().split())
grid = [input().strip() for _ in range(n)]

ans = 64
for i in range(n - 7):
    for j in range (m - 7):
        ans = min(repaint(i,j), ans)

print(ans)