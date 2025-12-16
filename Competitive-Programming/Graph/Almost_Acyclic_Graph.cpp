#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ind(n,0);
    for(int i=0;i<n;i++){
        for(auto x : adj[i]){
            ind[x]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i] == 0) q.push(i);
    }
    int cnt;
    while(!q.empty()){
        int u = q.front();
        cnt++;
        q.pop();
        for(auto v : adj[u]){
            ind[v]--;
            if(ind[v] == 0 )q.push(v);
        }
    }

    if(cnt == n){

    }else{
        
    }
}