#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> app(n);
    vector<int> apart(m);

    for(int i=0;i<n;i++) cin >> app[i]; 
    for(int i=0;i<m;i++) cin >> apart[i]; 
    //set<long long> seen(apart.begin(),apart.end());
    sort(app.begin(),app.end());
    sort(apart.begin(),apart.end());
    int i = 0,j = 0;
    // app = {45,60,60,80}
    // apart = {30,60,75} 
    int cnt = 0;
    while(i < n && j < m){
        if(app[i]+k >= apart[j] && app[i]-k <= apart[j]){
            cnt++;
            j++;
            i++;
        }
        else if(app[i]-k > apart[j]){
            j++;
        }else{
            i++;
        }
    }
    cout << cnt << endl;
}