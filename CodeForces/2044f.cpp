#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    vector<int> B(m);
    for(int i=0;i<m;i++) cin >> B[i];

    vector<vector<int>> M(n,vector<int>(m,0)); 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            M[i][j] = A[i] * B[j];
        }
    }
    for(int i=0;i<q;i++){
        int k;
        cin >> k;
    }
}