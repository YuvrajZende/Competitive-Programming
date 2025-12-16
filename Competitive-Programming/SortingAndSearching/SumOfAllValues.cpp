#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    bool flag = false;
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        while(j < k){
            int val = arr[i]+arr[j]+arr[k];
            if(val == x){
                flag = true;
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                break;
            }else if(val < x){
                j++;
            }else{
                k--;
            }
        }
    }
    if(!flag){
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}