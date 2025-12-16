#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*
void dfs(vector<vector<string>>& grid,int i,int j,vector<vector<int>>& vis,string path){

  if(i<0 || i >= n || j<0 || j>=m || grid[i][j] == "#" || vis[i][j] == 1){
    return;
  }
  if(grid[i][j] == "B"){
    ans = path;
    found = true;
    return;
  }
  vis[i][j] = 1;
  dfs(grid,i+1,j,vis,path+"D");
  dfs(grid,i,j+1,vis,path+"R");
  dfs(grid,i-1,j,vis,path+"U");
  dfs(grid,i,j-1,vis,path+"L");
  vis[i][j] = 0;
}
*/
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == "A"){
                dfs(grid,i,j,vis,"");
            }
        }
    }
    
    if(!found) cout << "NO";
    else{
      cout << "YES" << endl;
      cout << ans.size() << "\n";
      cout << ans << endl;
    }
    */
    queue<tuple<int,int,string>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A'){
                q.push({i,j,""});
                vis[i][j] = 1;
            }
        }
    }
    int dirx[] = {-1,0,1,0};
    int diry[] = {0,1,0,-1};
    string dir[] = {"U","R","D","L"};
    string ans = "";
    bool found = false;
    while(!q.empty()){
      auto [i,j,path] = q.front();
      q.pop();
      if(grid[i][j] == 'B'){
        ans = path;
        found = true;
        break;
      }
      for(int x=0;x<4;x++){
        int ni = i + dirx[x];
        int nj = j + diry[x];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != '#' && vis[ni][nj] == 0){
          vis[ni][nj] = 1;
          q.push({ni,nj,path+dir[x]});
        }
      }
    }
    if(!found){
      cout << "NO" << "\n";
    }else{
      cout << "YES" << "\n";
      cout << ans.size() << "\n";
      cout << ans << "\n";
    }
}