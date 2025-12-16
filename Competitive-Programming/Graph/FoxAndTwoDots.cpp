/*
Each cell contains a dot that has some color. We will use different uppercase Latin characters to express different colors.

The key of this game is to find a cycle that contain dots of same color. Consider 4 blue dots on the picture forming a circle as an example. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

These k dots are different: if i ≠ j then di is different from dj.
k is at least 4.
All dots belong to the same color.
For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Determine if there exists a cycle on the field.
*/

#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<vector<char>> grid;
vector<vector<int>> vis;

bool dfs(int i,int j,int pi,int pj,char color){
  vis[i][j] = 1;
  
  int dirx[] = {1,0,-1,0};
  int diry[] = {0,1,0,-1};
  
  for(int x=0;x<4;x++){
    
    int ni = dirx[x] + i;
    int nj = diry[x] + j;
    
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == color) {
            if (vis[ni][nj] == -1) {
                if (dfs(ni, nj, i, j, color)) return true;
            } 
            else if (ni != pi || nj != pj) {
                return true;  // found a cycle
            }
        }
  }
  return false;
}

int main(){
    cin>> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m, -1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == -1){
                if(dfs(i,j,-1,-1,grid[i][j]) == true){
                  flag = true;
                }
            }
        }
    }
    
    if(flag) cout << "Yes";
    else cout << "No";
}