#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> topo;
void dfs(int node){
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
    topo.push_back(node);
}

int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vis.assign(n+1,0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    
    vector<int> memo(n+1,1e9);

    memo[1] = 0;
    for(int u:topo){
        
    }
}