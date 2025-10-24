import heapq,sys
input = sys.stdin.readline


t = int(input())
for i in range(t):
    n = int(input())
    arr = []
    while len(arr) < n:
        arr +=(list(map(int, input().split())))
    
    min_pq = []
    max_pq = []
    result = []

    for j in range(1,n + 1):
        x = arr[j - 1]
        if len(min_pq) == len(max_pq):
            heapq.heappush(max_pq, -x)
        else:
            heapq.heappush(min_pq, x)
        
        if min_pq and -max_pq[0] > min_pq[0]:
            a = -heapq.heappop(max_pq)
            b = heapq.heappop(min_pq)
            heapq.heappush(max_pq, -b)
            heapq.heappush(min_pq, a)

        if j % 2 != 0:
            result.append(-max_pq[0])
    
    print(len(result))
    for i in range(len(result)):
        print(result[i], end = " ")
        if (i + 1) % 10 == 0:
            print()
    print()

        

