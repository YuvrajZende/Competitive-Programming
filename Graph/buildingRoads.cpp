#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
int find(int i){
    if(parent[i] != i){
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void Union(int i,int j){
    int per_i = find(i);
    int per_j = find(j);
    if(per_j != per_i) parent[per_j] = per_i;
}

int main(){
    int n,m;
    cin >> n >> m;
    // vector<vector<int>> cities(n);
    parent.resize(n+1);
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    vector<int> res;
    for(int i=1;i<=n;i++){
        if(find(i) == i){
            res.push_back(i);
        }
    }
    cout << res.size()-1 << endl;

    for (int i=1;i<res.size();i++){
        cout << res[0] << " " << res[i] << endl;
    }
}