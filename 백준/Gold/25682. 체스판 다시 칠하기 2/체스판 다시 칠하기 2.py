import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

BOARD = []
for _ in range(N):
    row = input().rstrip()
    BOARD.append(row)

# 왼쪽 최상단 black
B_PS = [[0] * (M + 1) for _ in range(N + 1)]

# 왼쪽 최상단 white
W_PS = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, M + 1):

        if (i + j) % 2 != 0:
            if BOARD[i - 1][j- 1] == 'B':
                B_PS[i][j] = 1 + B_PS[i][j - 1] + B_PS[i - 1][j] - B_PS[i - 1][j - 1]
                W_PS[i][j] = 0 + W_PS[i][j - 1] + W_PS[i - 1][j] - W_PS[i - 1][j - 1]
            else:
                B_PS[i][j] = 0 + B_PS[i][j - 1] + B_PS[i - 1][j] - B_PS[i - 1][j - 1]
                W_PS[i][j] = 1 + W_PS[i][j - 1] + W_PS[i - 1][j] - W_PS[i - 1][j - 1]
        else:
            if BOARD[i - 1][j - 1] == 'B':
                B_PS[i][j] = 0 + B_PS[i][j - 1] + B_PS[i - 1][j] - B_PS[i - 1][j - 1]
                W_PS[i][j] = 1 + W_PS[i][j - 1] + W_PS[i - 1][j] - W_PS[i - 1][j - 1]
            else:
                B_PS[i][j] = 1 + B_PS[i][j - 1] + B_PS[i - 1][j] - B_PS[i - 1][j - 1]
                W_PS[i][j] = 0 + W_PS[i][j - 1] + W_PS[i - 1][j] - W_PS[i - 1][j - 1]

ans = 5000000

for i in range(1, N - K + 2):
    for j in range(1, M - K + 2 ):
        BS = B_PS[i + K - 1][j + K - 1] - B_PS[i - 1][j + K - 1] - B_PS[i + K - 1][j - 1] + B_PS[i - 1][j - 1]
        WS = W_PS[i + K - 1][j + K - 1] - W_PS[i - 1][j + K - 1] - W_PS[i + K - 1][j - 1] + W_PS[i - 1][j - 1]
        ans = min(ans, BS, WS)

print(ans)