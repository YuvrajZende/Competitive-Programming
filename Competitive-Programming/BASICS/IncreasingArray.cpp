#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int left = 0,right = n-1;
    int ans = 0;
    while(right >= left){
        if(arr[right] < arr[left]){
            swap(arr[left],arr[right]);
            ans++;
        }else if(arr[right] > arr[left]){
            right--;
        }
    }
    cout << ans << endl;
}