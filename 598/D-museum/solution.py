def count(x, y):
    if visited[x][y] != 0: return 0
    if grid[x][y] == '*': return 1
    visited[x][y] = component
    return count(x-1, y) + count(x, y-1) + count(x+1, y) + count(x, y+1)

n, m, k = map(int, input().split())

grid = []
for _ in range(n):
    grid.append(input())

ans, visited, component = {0: 0}, [[0] * (m) for _ in range(n)], 1
while(k):
    x, y = map(int, input().split())
    x, y = x-1, y-1
    if visited[x][y] == 0:
        ans[component] = count(x, y)
        component = component + 1
    k = k - 1
    print(ans[visited[x][y]])