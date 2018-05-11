import math

n = int(input())

vectors = []
for i in range(n):
    x, y = map(int, input().split())
    vectors.append((math.atan2(y, x), i + 1))
vectors.sort()

best = 2 * math.pi - abs(vectors[0][0]) - abs(vectors[n-1][0])
p1, p2 = vectors[0][1], vectors[n-1][1]
for i in range(n - 1):
    current = vectors[i+1][0] - vectors[i][0]
    print(current, vectors[i][1], vectors[i+1][1])
    if (current < best and current != 0):
        best = current
        p1, p2 = vectors[i][1], vectors[i+1][1]

print(p1, p2)