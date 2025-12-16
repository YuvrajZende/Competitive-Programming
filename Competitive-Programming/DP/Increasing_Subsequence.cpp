
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;

int subseq(vector<long long> arr,int i,vector<int>& dp,int prev){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int take = 0,ntake = 0;
    if(arr[i] > prev){
        take = 1 + subseq(arr,i+1,dp,arr[i]);
    }
    ntake = subseq(arr,i+1,dp,prev);
    return dp[i] = max(take,ntake);
}

int main(){
    
    cin >> n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> dp(n+1,-1);

    cout << subseq(arr,0,dp,-1) << endl;
    /*
    vector<int> dp(n+1,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << endl;
    */
}