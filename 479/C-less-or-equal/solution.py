n, k = map(int, input().split())
a = sorted(map(int, input().split()))

if k == 0:
    print([-1, a[0] - 1][a[0] >= 2])
else:
    print([-1, a[k-1]][k == n or a[k] != a[k-1]])
