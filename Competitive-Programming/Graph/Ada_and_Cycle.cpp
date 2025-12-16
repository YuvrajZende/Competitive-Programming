/*
Ada the Ladybug is on a trip in Bugindia. There are many cities and some uni-directional roads connecting them. Ada is wondering about the shortest path, which begins in a city and ends in the same city. Since Ada likes short trips, she asked you to find the length of such path for each city in Bugindia.

Input
The first line will contain 0 < N ≤ 2000, the number of cities.

Then N lines follow, each containing N integers 0 ≤ Hij ≤ 1. One means, that there is a road between i and j (zero means there isn't a road).

Output
Print N lines, the length of shortest path which begins in city i and ends in city i. If the path doesn't exist, print "NO WAY" instead.
*/

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

bool dfs(){
    
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    vector<vector<int>> graph;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
            graph[j].push_back(i);
        }
    }
    vector<int> vis(n,INT_MAX);
    vector<int> path(n);
    for(int i=0;i<n;i++){
        if(vis[i] == -1){
            
        }
    }
}