#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int> > &graph, vector<bool> &visited, bool &isCyclic) {
    visited[v] = true;
    if (graph[v].size() != 2) isCyclic = false;
    for (auto u: graph[v])
        if (!visited[u]) 
            dfs(u, graph, visited, isCyclic);
}

int findComponents(int n, vector<vector<int> > &graph, vector<int> &deg) {
    vector<bool> visited(n + 1);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool isCyclic = true;
            dfs(i, graph, visited, isCyclic);
            count += isCyclic;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n + 1);
    vector<int> deg(n + 1);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;

    }
    cout << findComponents(n, graph, deg) << endl;
    return 0;
}
