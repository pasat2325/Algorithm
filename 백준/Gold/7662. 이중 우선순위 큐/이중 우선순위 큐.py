from collections import defaultdict
import heapq, sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    d = defaultdict(int)
    max_q, min_q = [], []

    for _ in range(n):
        cmd, val = input().split()
        val = int(val)

        if cmd == 'I':
            heapq.heappush(max_q, -val)
            heapq.heappush(min_q, val)
            d[val] += 1

        elif cmd == 'D':
            if val == 1:  # 최댓값 삭제
                while max_q and d[-max_q[0]] == 0:
                    heapq.heappop(max_q)
                if max_q:
                    d[-max_q[0]] -= 1
                    heapq.heappop(max_q)
            elif val == -1:  # 최솟값 삭제
                while min_q and d[min_q[0]] == 0:
                    heapq.heappop(min_q)
                if min_q:
                    d[min_q[0]] -= 1
                    heapq.heappop(min_q)

    while max_q and d[-max_q[0]] == 0:
        heapq.heappop(max_q)
    while min_q and d[min_q[0]] == 0:
        heapq.heappop(min_q)

    if not max_q:
        print("EMPTY")
    else:
        print(-max_q[0], min_q[0])