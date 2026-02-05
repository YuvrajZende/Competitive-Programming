#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> tickets(n);
    for(int i=0;i<n;i++) cin >> tickets[i];
    vector<int> MaxPrice(n);
    for(int i=0;i<m;i++) cin >> MaxPrice[i];
    sort(tickets.begin(),tickets.end());
    //sort(MaxPrice.begin(),MaxPrice.end());
    vector<int> res(m,-1);
    int i=0,j=0;
    while(i < n && j < m){
        if(tickets[i] <= MaxPrice[j]){
            res[j] = tickets[i];
            i++;
            j++;
        }else if(tickets[i] > MaxPrice[j]){
            j++;
        }else{
            i++;
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
}