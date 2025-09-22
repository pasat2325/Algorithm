import sys
import heapq


input = sys.stdin.readline

if __name__ == "__main__":
    N,M = map(int, input().split())
    ix, iy = map(int, input().split())
    ix, iy = ix - 1, iy - 1
    a, b, c = map(int, input().split())
    H = []

    tpx, tpy, tph = -1, -1, -1
    for i in range(N):
        row = list(map(int,input().split()))
        H.append(row)
        for j, h in enumerate(row):
            if h > tph:
                tph = h
                tpx, tpy = i, j

    INF = int(5e9)
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    dist = [[INF for j in range(M)] for i in range(N)]
    pq = []
    dist[ix][iy] = 0

    heapq.heappush(pq, (0, ix, iy))

    while pq:
        d, x, y = heapq.heappop(pq)
        
        if d != dist[x][y]:
            continue

        if x == tpx and y == tpy:
            print(d)
            sys.exit(0)

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            dh = H[nx][ny] - H[x][y]
            if abs(dh) > c:
                continue

            w = 1 if dh == 0 else (dh * a if dh > 0 else -dh * b)

            if dist[nx][ny] > d + w:
                dist[nx][ny] = d + w
                heapq.heappush(pq, (dist[nx][ny], nx, ny))
    
    print(-1)




