import heapq, sys
input = sys.stdin.readline
n = int(input())
pq = []
for i in range(n):
    x = int(input())
    org = x
    if pq and x == 0:
        print(heapq.heappop(pq)[1])
    elif not pq and x == 0:
        print(0)
    else:
        if x < 0:
            x = -x
        
        heapq.heappush(pq,(x, org))
