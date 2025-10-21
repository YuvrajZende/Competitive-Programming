#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n,m;

int main(){
    cin >> n >> m;
    vector<vector<int>> board(8,vector<int>(8,INT_MAX));

    queue<pair<int,int>> q;
    int time = 1;

    q.push({n-1,m-1});

    board[n-1][m-1] = time;
    vector<pair<int,int>> dir = {{-2,1},{-2,-1},{-1,-2},{1,-2},{2,1},{2,-1},{-1,2},{1,2}};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == INT_MAX){
                board[nx][ny] = min(board[nx][ny],++time);
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<< board[i][j];
        }
        cout<<endl;
    }
}