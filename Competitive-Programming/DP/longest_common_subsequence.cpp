
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n,m;

int subseq(vector<long long> &arr1,vector<long long> &arr2,int i,int j,
vector<vector<int>>& dp){
    if(i == n || j == m){
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if(arr1[i] == arr2[j]){
        return dp[i][j] = 1 + subseq(arr1,arr2,i+1,j+1,dp);
    }else{
        return dp[i][j] = max(subseq(arr1,arr2,i+1,j,dp),subseq(arr1,arr2,i,j+1,dp));
    }
}

int main(){
    
    cin >> n >> m;
    vector<long long> arr1(n);
    for(int i=0;i<n;i++) cin >> arr1[i];
    
    vector<long long> arr2(m);
    for(int j=0;j<m;j++) cin >> arr2[j];

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    vector<long long> ans;
    subseq(arr1,arr2,0,0,dp);

    int i = 0,j=0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++,j++;
        }else if(dp[i+1][j] >= dp[i][j+1] ){
            i++;
        }else{
            j++;
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}