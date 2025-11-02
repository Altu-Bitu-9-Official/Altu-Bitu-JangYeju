#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    for (int next = 1; next <= n; ++next) {
        if (graph[node][next] == 1 && !visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main(){
    cin >> n >> m;
    graph.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    visited[1] = true;
    dfs(1);

    int count =0;
    for(int i=2;i<=n;i++){
        if(visited[i]) count++;
    }
    cout << count << '\n';

    return 0;
}