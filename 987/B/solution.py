import math
x, y = map(int, input().split())

res1 =  math.log(x, 2) * y
res2 = math.log(y, 2) * x

if res1 == res2:
    print("=")
elif res1 < res2:
    print("<")
else:
    print(">")
