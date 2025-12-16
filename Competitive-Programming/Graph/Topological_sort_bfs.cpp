
/*Problem statement: Given a graph, find the topological order for the given graph.

Topological sort: The linear ordering of nodes/vertices such that if there exists an edge
 between 2 nodes u,v then ‘u’ appears before ‘v’.*/

// Input: V = 6,
/*
6 6
2 3
3 1
4 0
4 1
5 0
5 2
*/
// adj=[ [ ], [ ], [3], [1], [0,1], [0,2] ]
// Output: [5, 4, 2, 3, 1, 0]

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int V,E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for(int i=0;i<V;i++){
        int u,v;
        cin >> u >> v;
        graph[v].push_back(u);
    }

    vector<int> indegree(E);
    for(int i=0;i<V;i++){
        for(auto x : graph[i]){
            indegree[x] ++;
        }
    }

    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> ans;
    while (!q.empty()){
        auto u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto x : graph[u]){
            indegree[x] --;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}