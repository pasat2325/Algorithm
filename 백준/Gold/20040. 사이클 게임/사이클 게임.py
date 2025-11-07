import sys
n, m = map(int, input().split())

parent = [i for i in range(n)]

def find_root(x):
    if parent[x] == x:
        return x
    
    parent[x] = find_root(parent[x])
    return parent[x]

def union_set(x, y):
    x = find_root(x)
    y = find_root(y)

    if (x > y):
        parent[x] = y
    else:
        parent[y] = x
    return

def is_same_set(x, y):
    x = find_root(x)
    y = find_root(y)
    return x == y

for i in range(1, m + 1):
    a,b = map(int, input().split())
    
    if (is_same_set(a,b)):
        print(i)
        sys.exit(0)

    union_set(a,b)

print(0)

