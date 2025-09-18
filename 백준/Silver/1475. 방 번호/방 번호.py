n = input()
remains = [0] * 10
ans = 0
for ch in n:
    digit = int(ch)
    if digit == 6 or digit == 9:
        if remains[6] == 0 and remains[9] == 0:
            ans += 1
            remains = [x + 1 for x in remains]
        
        if remains[6]:
            remains[6] -= 1
        elif remains[9]:
            remains[9] -= 1 

    else:
        if remains[digit] == 0:
            ans += 1
            remains = [x + 1 for x in remains]
        remains[digit] -= 1

print(ans)
