#include<iostream>
#include<vector>

using namespace std;

/*
int funt(vector<int>& prices,vector<int>& pages,int idx,int price,vector<vector<int>>& dp){
    if(idx < 0){
        return 0;
    }
    if (dp[idx][price] != -1){
        return dp[idx][price];
    }
    int take = 0,ntake = 0;
    if(price - prices[idx] >= 0){
        take = pages[idx] + funt(prices,pages,idx-1,price - prices[idx],dp);
    }
    ntake = funt(prices,pages,idx-1,price,dp);

    return dp[idx][price] = max(take,ntake);
}
*/

int main(){
    int n,x;  // n as no of books
    cin >> n >> x; // x as max total price
    vector<int> prices(n);
    vector<int> pages(n);

    vector<vector<int>> dp(n,vector<int>(x+1,-1));

    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    for(int i=0;i<n;i++){
        cin >> pages[i];
    }
    //int ans = funt(prices,pages,n-1,x,dp);
    //cout << ans;

    
}