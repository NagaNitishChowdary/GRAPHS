// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
  
bool detectCycle(int node,vector<int> adj[],int V,int vis[]){
    vis[node] = 1 ; 
    queue<pair<int,int>> q ;
    q.push({node,-1});
    while(!q.empty()){
        int node = q.front().first ;
        int parent = q.front().second ;
        q.pop() ;
        for(auto adjacentNode:adj[node]){
            if(vis[adjacentNode] == 0){ 
                vis[adjacentNode] = 1 ;
                q.push({adjacentNode,node}) ;
            }
            else if(parent != adjacentNode) return true ;
        }
    }
    return false ;
} 

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        if(vis[i] == 0){
            if(detectCycle(i,adj,V,vis)) return true ;
        }
    }
    return false ;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = isCycle(V, adj);
        if (ans) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
