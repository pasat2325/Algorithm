import sys
import heapq
input = sys.stdin.readline

# 컴퓨터 a 가 b 를 의존하면, b가 감염될 시 a가 s초 뒤 감염되므로 b -> a 로 가는 단방향 간선이 존재한다


t = int(input())

for _ in range(t):
    n,d,c = map(int,input().split())
    adj = [[] for _ in range(n + 1)]

    for i in range(d):
        a,b,s = map(int, input().split())
        adj[b].append((a,s))
    
    INF = int(1e9)
    dist = [INF for i in range(n + 1)]
    pq = []

    dist[c] = 0
    heapq.heappush(pq, (0, c))

    while pq:
        d, c = heapq.heappop(pq)

        if d != dist[c]:
            continue

        for i in range(len(adj[c])):
            nxt, w = adj[c][i]
            
            if dist[nxt] > d + w:
                dist[nxt] = d + w
                heapq.heappush(pq, (dist[nxt], nxt))
    
    sec = 0
    cnt = 0
    for i in range(n + 1):
        if dist[i] != INF:
            cnt += 1
            sec = max(sec, dist[i])
    
    print(cnt, sec)

