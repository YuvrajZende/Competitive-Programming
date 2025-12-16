#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, unordered_map<int, vector<int>>& graph, int n) {
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int nxt : graph[node]) {
            if (dist[nxt] == INT_MAX) {
                dist[nxt] = dist[node] + 1;
                q.push(nxt);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int arin, bran, outpost;
    cin >> arin >> bran >> outpost;

    auto dist_arin = bfs(arin, graph, n);
    auto dist_bran = bfs(bran, graph, n);

    if (dist_arin[outpost] == INT_MAX || dist_bran[outpost] == INT_MAX) {
        cout << "Impossible\n";
        return 0;
    }

    int min_total = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (i == outpost) continue;
        if (dist_arin[i] != INT_MAX && dist_bran[i] != INT_MAX) continue;
    }
    min_total = dist_arin[outpost] + dist_bran[outpost] + 1;

    cout << min_total << "\n";
    return 0;
}