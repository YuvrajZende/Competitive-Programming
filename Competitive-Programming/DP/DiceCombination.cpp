#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int MOD = 1e9+7;

    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }
    }
    cout<< dp[n]<<endl;
} 