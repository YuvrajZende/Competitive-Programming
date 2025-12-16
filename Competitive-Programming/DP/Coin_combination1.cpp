

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int MOD = 1e9 + 7;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i]; 
    }

    vector<int> amount(x+1,0);
    amount[0] = 1; 
    for(int i =1;i<=x;i++){
        for(int coin : coins){
          if(i-coin >= 0){
            amount[i] = (amount[i] + amount[i - coin]) % MOD;
          }
        }
    }

    cout << amount[x];
}