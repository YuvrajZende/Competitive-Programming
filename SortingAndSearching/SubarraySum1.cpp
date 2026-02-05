#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    /*
    int cnt = 0;
    for(int i=0;i<n;i++){
        long long val = 0;
        for(int j=i;j<n;j++){
            val += arr[j];
            if(val == x) cnt++;
        }
    }
    */
    unordered_map<long long,int> seen;
    seen[0] = 1;
    int cnt = 0;
    long long pref = 0;
    for(int i=0;i<n;i++){
        pref += arr[i];
        if(seen.find(pref-x) != seen.end()){
            cnt += seen[pref-x];
        }
        seen[pref] += 1;
    }
    cout << cnt << endl;
}