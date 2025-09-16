import sys
input = sys.stdin.readline
tc = int(input())
for _ in range(tc):
    str = input().strip()
    lstack=[]
    rstack=[]
    for ch in str:
        if ch =='<'and len(lstack) > 0:
            rstack.append(lstack[-1])
            lstack.pop()
        elif ch == '>' and len(rstack) > 0:
            lstack.append(rstack[-1])
            rstack.pop()
        elif ch =='-' and len(lstack) > 0:
            lstack.pop()
        elif ch != '<' and ch != '>' and ch != '-':
            lstack.append(ch)

    lstack.extend(reversed(rstack))
    print("".join(lstack))

   