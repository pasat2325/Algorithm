import sys
input = sys.stdin.readline
s= input().strip()

stack = []
ans = 0
prev = ''

for ch in s:
    if ch == '(':
        stack.append('(')
        prev = '('
        continue

    else:
        stack.pop()
        if prev == '(':
            ans += len(stack)
        else:
            ans += 1
        prev = ')'


print(ans)