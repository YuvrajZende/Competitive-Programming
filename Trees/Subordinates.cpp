#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> sub(n-1);
    for(int i=0;i<n-1;i++){
        cin >> sub[i];
    }
    vector<vector<int>> adj(n);
    for(int i=2;i<n-1;i++){
        adj[sub[i]].push_back(i);
        adj[i].push_back(sub[i]);
    }

    
}