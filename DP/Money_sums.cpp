#include<bits/stdc++.h>

using namespace std;

// void count(vector<int>& arr,int i,long long tot,vector<long long>& res){
//     if(i == arr.size()){
//         res.push_back(tot);
//         return;
//     }
//     count(arr,i+1,tot,res);
//     count(arr,i+1,tot+arr[i],res);
// }

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // count(arr,0,0,res);

    set<int> seen;
    seen.insert(0);
    for(int x : arr){
        set<int> a = seen;
        for(int z : seen){
            a.insert(z+x);
        }
        seen = a;
    }
    seen.erase(0);

    cout << seen.size() << endl;
    for(auto x:seen){
        cout << x << " ";
    }
}