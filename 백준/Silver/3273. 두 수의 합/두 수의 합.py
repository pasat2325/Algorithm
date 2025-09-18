n = int(input())
arr = list(map(int, input().split()))
x = int(input())

arr.sort()

front = 0
rear = n - 1
ans = 0
while(front < rear):
    if arr[front] + arr[rear] == x:
        front += 1
        rear -= 1
        ans += 1
    elif arr[front] + arr[rear] > x:
        rear -= 1
    else:
        front += 1
    
print(ans)
