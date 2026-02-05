#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x) : val(x),next(nullptr){}
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}