#include <cstdio>

using namespace std;

char grid[1001][1001];
int visited[1001][1001];
int ans[1000001];
int n, m, k, component = 1;

int count(int x, int y) {
    if (visited[x][y]) return 0;
    if (grid[x][y] == '*') return 1;
    if (grid[x][y] == '.') visited[x][y] = component;
    return count(x-1, y) + count(x, y-1) + count(x+1, y) + count(x, y+1);
}

int main()
{
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &grid[i][j]);
        }
        scanf("\n");
    }
    int x, y;
    while (k--) {
        scanf("%d %d\n", &x, &y);
        if (!visited[x][y]) {
            ans[component] = count(x, y);
            component++;
        }
        printf("%d\n", ans[visited[x][y]]);
    }
    return 0;
}