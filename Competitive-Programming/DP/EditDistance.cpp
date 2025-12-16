#include<bits/stdc++.h>

using namespace std;

int EditDistance(string s1,int i,string s2,int j,
vector<vector<int>>& dp){
    if(i == 0){
        return j;
    }
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = EditDistance(s1,i-1,s2,j-1,dp);
    }else{
        int add = 0,dele = 0,upd = 0;
        add = EditDistance(s1,i,s2,j-1,dp)+1;
        dele = EditDistance(s1,i-1,s2,j,dp)+1;
        upd = EditDistance(s1,i-1,s2,j-1,dp)+1;
        return dp[i][j] = min(add,min(dele,upd));
    }
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(),m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout << EditDistance(s1,n,s2,m,dp) << endl;

    dp[0][0] = 0;
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=m;i++) dp[0][i] = i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int add = dp[i][j-1] + 1;
                int rem = dp[i-1][j] + 1;
                int up = dp[i-1][j-1] + 1;
                dp[i][j] = min(add,min(rem,up));
            }
        }
    }
    cout << dp[n][m] << endl;
}