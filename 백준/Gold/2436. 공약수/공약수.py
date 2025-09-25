import math

def cal_gcd(x,y):
    return y if x % y == 0 else cal_gcd(y, x % y)

gcd, lcm = map(int, input().split())
div = lcm // gcd
sdiv = int(math.sqrt(div)) + 1

resa = 0
resb = 0
for i in range(1,sdiv):
    if(div % i == 0):
        a= i
        b = div // i

        if cal_gcd(a,b) == 1:
            resa = a
            resb = b

print(resa * gcd, resb * gcd)    