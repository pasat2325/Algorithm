import sys
input = sys.stdin.readline

idx = 1
while 1:
    row = input().rstrip()

    if row == "0":
        break
    
    print(f"Case {idx}: Sorting... done!")
    idx += 1
