import sys
from collections import deque

input = sys.stdin.readline

delta = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def solution():

    def find(n):
        temp = n
        while group[n] != n:
            n = group[n]
        group[temp] = n
        return n

    def union(n1, n2):
        n1 = find(n1)
        n2 = find(n2)
        if n1 > n2:
            n1, n2 = n2, n1
        group[n2] = n1

    R, C = map(int, input().split())
    board = [[*input().rstrip()] for _ in range(R)]
    visited = [[0]*C for _ in range(R)]
    group = [i for i in range(R*C)]
    swans = []
    _queue = deque()
    for i in range(R):
        for j in range(C):
            if visited[i][j] == 0 and board[i][j] != 'X':
                queue = deque([(i, j)])
                visited[i][j] = 1
                while queue:
                    r, c = queue.popleft()
                    if board[r][c] == 'L':
                        swans.append((r, c))
                    for dr, dc in delta:
                        nr, nc = r+dr, c+dc
                        if R > nr >= 0 and C > nc >= 0:
                            if visited[nr][nc] == 0:
                                if board[nr][nc] != 'X':
                                    queue.append((nr, nc))
                                    union(r*C+c, nr*C+nc)
                                else:
                                    _queue.append((nr, nc))
                                visited[nr][nc] = 1
    idx1 = swans[0][0]*C+swans[0][1]
    idx2 = swans[1][0]*C+swans[1][1]
    queue = _queue
    day = 0
    while find(idx1) != find(idx2):
        day += 1
        _queue = deque()
        while queue:
            r, c = queue.popleft()
            for dr, dc in delta:
                nr, nc = r+dr, c+dc
                if R > nr >= 0 and C > nc >= 0:
                    if visited[nr][nc] == 0:
                        visited[nr][nc] = day+1
                        _queue.append((nr, nc))
                    elif visited[nr][nc] != day+1:
                        union(r*C+c, nr*C+nc)
        queue = _queue
    print(day)

solution()