import sys
def is_seq(num):
    if(num < 100):
        return True
    
    x = num % 10
    y = int(num / 10) % 10
    diff = x - y

    num = int(num / 10)
    
    x = num % 10
    y = int(num / 10) % 10
    if(diff == x - y):
        return True
    else:
        return False
    
n = int(input())
arr = [0] * 1001
for i in range(1, 1001):
    if i == 1000:
        arr[i] = arr[i - 1]
    else:
        if(is_seq(i)):
            arr[i] = arr[i - 1] + 1
        else:
            arr[i] = arr[i - 1] 

print(arr[n])