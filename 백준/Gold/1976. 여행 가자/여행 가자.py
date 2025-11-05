n = int(input())
m = int(input())

parent = [i for i in range(n + 1)]

def find_parent(city):
    if parent[city] == city:
        return city
    parent[city] = find_parent(parent[city])

    return parent[city]

def union_city(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if(a < b):
        parent[b] = a
    else:
        parent[a] = b
    return

for i in range(n):
    cur_city = i + 1
    conn = list(map(int,input().split()))

    for j in range(n):
        nx_city = j + 1

        if cur_city == nx_city or conn[nx_city - 1] == 0:
            continue

        union_city(cur_city, nx_city)

plan = list(map(int,input().split()))

root = find_parent(plan[0])

f = True
for i in range(1, m):
    temp = find_parent(plan[i])
    if root != temp:
        f= False
        break

if f:
    print("YES")
else:
    print("NO")