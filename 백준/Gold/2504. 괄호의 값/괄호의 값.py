import sys

s = input().rstrip()

stack = []
temp = 1
ans = 0

for i, ch in enumerate(s):
    if ch == "(":
        temp = temp * 2
        stack.append(ch)

    elif ch == "[":
        temp = temp * 3
        stack.append(ch)

    elif ch == ")":
        if not stack or stack[-1] != "(":
            ans = 0
            print(ans)
            sys.exit(0)
        
        if(s[i - 1] == "("):
            ans = ans + temp
        
        temp = temp // 2
        stack.pop()
    
    elif ch == "]":
        if not stack or stack[-1] != "[":
            ans = 0
            print(ans)
            sys.exit(0)
        
        if (s[i - 1] == "["):
            ans = ans + temp
        
        temp = temp // 3
        stack.pop()

if stack:
    print(0)
else:
    print(ans)

        
