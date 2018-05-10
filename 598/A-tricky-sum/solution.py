import math

t = int(input())

for i in range(t):
    n = int(input())
    print(n*(n+1)//2 - 2*sum([2**x for x in range(int(math.log(n, 2))+1)]))
