import math
testcase = int(input())
for _ in range(testcase):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    centerD = math.sqrt((x2-x1)**2+(y2-y1)**2)
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    elif abs(r1-r2) < centerD < r1+r2:
        print(2)
    elif centerD == r1 + r2 or centerD == abs(r2-r1):
        print(1)
    elif x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    else:
        print(0)
    
