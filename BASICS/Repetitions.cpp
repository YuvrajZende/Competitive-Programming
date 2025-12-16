#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int length = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i == 0 || s[i] == s[i-1]){
            length++;
        }else{
            length = 1;
        }
        ans = max(ans,length);
    }

    cout << ans << endl;
}