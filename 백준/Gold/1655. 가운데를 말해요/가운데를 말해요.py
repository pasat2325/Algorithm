import heapq,sys
input = sys.stdin.readline
min_pq = []
max_pq = []

n = int(input())
for i in range(n):

    x = int(input())
    if len(min_pq) == len(max_pq):
        heapq.heappush(max_pq, -x)
    else:
        heapq.heappush(min_pq, x)
    
    if min_pq and -max_pq[0] > min_pq[0]:
        a = -heapq.heappop(max_pq)
        b = heapq.heappop(min_pq)
        heapq.heappush(max_pq, -b)
        heapq.heappush(min_pq, a)

    print(-max_pq[0])
