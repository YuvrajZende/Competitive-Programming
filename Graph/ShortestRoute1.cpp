#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    const long long INF = LLONG_MAX; 
    vector<long long> res(n+1,INF);  // INT_MAX will not work here  
    res[1] = 0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto [weight,city] = pq.top();
        pq.pop();
        if(weight > res[city]) continue;
        for(auto x : adj[city]){
            long long v = x.first;
            long long w = x.second;
            if(weight + w < res[v]){
                res[v] = weight + w;
                pq.push({res[v],v});
            }
        }
    }
    for(int i=1;i<res.size();i++){
        cout << res[i] << endl;
    }
}