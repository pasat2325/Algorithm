import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    grid = [[0 for i in range(1001)] for j in range(1001)]
    
    for t in range(n):
        x1, y1, width, height = map(int, input().split())

        x2 = x1 + width
        y2 = y1 + height

        for i in range(y1, y2):
            for j in range(x1, x2):
                grid[i][j] = t + 1

    ans_arr = [0] * (n + 1)
    for i in range(1001):
        for j in range(1001):
            if grid[i][j] == 0:
                continue
            ans_arr[grid[i][j]] += 1
    
    for i in range(1, n + 1):
        print(ans_arr[i])

                     

