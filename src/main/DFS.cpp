#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    cout << "Enter edges (u v) where u and v are node indices (0 to " << n-1 << "):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);

    return 0;
}

