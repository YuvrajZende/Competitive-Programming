#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long tot = 0;
    vector<int> val(n-1);
    long long a = 0;
    for(int i=0;i<n;i++){
        cin>> val[i]; 
        a += val[i];
    }
    tot = (n*(n-1))/2;

    cout<< tot - a << endl;
}