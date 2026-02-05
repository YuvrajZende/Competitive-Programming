#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> ind(n+1,0);
    for(int i=1;i<=n;i++){
        for(int x : adj[i]){
            ind[x]++;
        }
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if(ind[i] == 0) q.push(i);
    }
    int cnt = 0;
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        cnt ++;
        for(int x : adj[node]){
            ind[x]--;
            if(ind[x] == 0)q.push(x);
        }
    }
    if(cnt == n){
        for(int x : res){
            cout << x << endl;
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}