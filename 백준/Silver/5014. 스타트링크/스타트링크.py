import sys
from collections import deque
input = sys.stdin.readline

f,s,g,u,d = map(int, input().split())
res = -1

def bfs(flr, cnt):
    global res
    visited = [False] * (f + 1)
    q = deque()
    q.append((flr, cnt))
    visited[flr] = True

    while q:
        qq = q.popleft()
        curf = qq[0]
        curc = qq[1]
        if (curf == g):
            res = curc
            break

        nxf = curf + u
        if (nxf <= f and visited[nxf] == False):
            visited[nxf] = True
            q.append((nxf, curc + 1))
        
        nxf = curf - d
        if (nxf >= 1 and visited[nxf] == False):
            visited[nxf] = True
            q.append((nxf, curc + 1))

bfs(s, 0)
if (res == -1):
    print("use the stairs")
else:
    print(res)