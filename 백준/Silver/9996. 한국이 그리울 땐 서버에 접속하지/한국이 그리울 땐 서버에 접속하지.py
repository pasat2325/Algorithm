import sys
input = sys.stdin.readline

n = int(input())
pattern = input().rstrip()

idx = 0
for i in range(len(pattern)):
    if pattern[i] == '*':
        idx = i

left = pattern[:idx]
right = pattern[idx + 1:]

while(n):
    str = input().rstrip()
    
    if len(str) < len(left) + len(right):
        print("NE")
        n -= 1
        continue

    lf = True
    for i in range(len(left)):
        
        if left[i] != str[i]:
            lf = False 
    
    rf = True
    for i in range(len(right)):
        if right[len(right) - 1 - i] != str[len(str) - 1 - i]:
            rf = False
    
    if lf and rf:
        print("DA")
    else:
        print("NE")
    n -= 1

