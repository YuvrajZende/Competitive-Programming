
#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;

void subseq(vector<int> arr1,vector<int> arr2,int i,int j){
    if(i < 0 || j < 0){
        return;
    }
    if(arr1[i] == arr2[j]){
        ans.push_back(arr1[i]);
        subseq(arr1,arr2,i-1,j-1);
    }else{
        subseq(arr1,arr2,i-1,j);
        subseq(arr1,arr2,i,j-1);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    subseq(arr1,arr2,n-1,m-1);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
}