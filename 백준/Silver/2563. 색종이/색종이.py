n = int(input())
grid = [[0] * 100 for i in range(100)]

for _ in range(n):
    x, y = map(int, input().split())

    for i in range(x, 10 + x):
        for j in range(y, 10 + y):
            grid[i][j] = 1

answer = 0
for i in range(100):
    for j in range(100):
        answer += grid[i][j]

print(answer)