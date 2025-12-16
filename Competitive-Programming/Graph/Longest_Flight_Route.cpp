#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ind(n,0);
    queue<int> q;
    for(int i=0;i<m;i++){
        for(auto v:adj[i]){
            ind[v]++;
        }
    }
    for(int i=0;i<n;i++){
        if(ind[i]==0) q.push(i);
    }

    int cnt = 0;
    vector<int> res;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        cnt++;
        for(auto v : adj[u]){
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    }
    if(cnt != n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }else{
        cout << res.size() << endl;
        for(auto x: res){
            cout << x << " ";
        }
    }
}