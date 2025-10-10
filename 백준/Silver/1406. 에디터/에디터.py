from collections import deque
import sys
string = deque(list(map(str,sys.stdin.readline().rstrip())))
n = int(input())
string2 = deque()
for i in range(n):
    x = sys.stdin.readline().rstrip()
    if x == "L" and len(string) != 0 :
        string2.appendleft(string[-1])
        string.pop()

    elif x == "D" and len(string2) != 0:
        string.append(string2[0])
        string2.popleft()
    
    elif x== "B" and len(string) != 0:
        string.pop()

    elif x[0] == "P":
        string.append(x[2])
string.extend(string2)
string = list(string)
print(''.join(string))

