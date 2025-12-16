#include<iostream>
#include<bits/stdc++.h>
/*
10 10
##..###..#
..#.#.....
..#...####
#.....##..
..#...#..#
.##.#.##..
.......#..
..........
...#.#....
..#..#...#
*/
using namespace std;

int n,m;

// O(n*n) for the dfs
void dfs(vector<vector<char>>& floor,int i,int j){
    floor[i][j] = '#';
    int dirx[] = {1,0,-1,0};
    int diry[] = {0,1,0,-1};
    for(int x=0;x<4;x++){
        int nx = i + dirx[x];
        int ny = j + diry[x];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && floor[nx][ny] == '.'){
            dfs(floor,nx,ny);
        }
    }
}

void bfs(vector<vector<char>>& floor,int i,int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    floor[i][j] = '#';
    int dirx[] = {1,0,-1,0};
    int diry[] = {0,1,0,-1};
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int x=0;x<4;x++){
            int nx = i + dirx[x];
            int ny = j + diry[x];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && floor[nx][ny] == '.'){
                floor[nx][ny] = '#';
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    vector<vector<char>> floor(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> floor[i][j];
        }
    }
    int cnt = 0;
    // O(n*n) for iterating through the floor

    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(floor[i][j] == '.'){
                dfs(floor,i,j);
                cnt++;
            }
        }
    }
    */

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(floor[i][j] == '.'){
                bfs(floor,i,j);
                cnt++;
            }
        }
    }
    cout << cnt ;
}