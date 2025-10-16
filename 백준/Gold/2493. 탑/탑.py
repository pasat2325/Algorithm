n=int(input())
arr = list(map(int, input().split()))
stack = []
res = [0] * n

stack.append((0, 100000001))
for idx,x in enumerate(arr):
    while stack[-1][1] <= x:
        stack.pop()
    
    res[idx]= stack[-1][0]
    stack.append((idx + 1, x))
  
print(*res)