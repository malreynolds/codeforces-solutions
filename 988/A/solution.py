n, k = map(int, input().split())

a = list(map(int, input().split()))
x = {}
for i in range(n):
    if a[i] not in x:
        x[a[i]] = i + 1
    
if len(x) >= k:
    print("YES")
    for key, val in x.items()[:k]:
        print(val, end=" ")
else:
    print("NO")
