#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m,q;
    cin >> n >> m >> q;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    vector<long long> res(q);
    for(int i=0;i<q;i++){
        int str,des;
        cin >> str >> des;
        priority_queue<pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<>> pq;
        pq.push({0,str});
        const long long INF = LLONG_MAX;
        vector<long long> vis(n+1,INF);
        vis[str] = 0;
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            if(node == des){
                break;
            }
            if(vis[node] < wt) continue;
            for(auto x : adj[node]){
                int v = x.first;
                long long w = x.second;
                if(wt + w < vis[v]){
                    vis[v] = wt + w;
                    pq.push({vis[v],v});
                }
            }
        }
        if(vis[str] == INF) res[i] = -1;
        else res[i] = vis[des];
    }

    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
}