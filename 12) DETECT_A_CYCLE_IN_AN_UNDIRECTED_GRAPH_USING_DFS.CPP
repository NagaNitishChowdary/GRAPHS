// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;

bool detectCycleDFS(int node,int parent,vector<int> adj[],int V,int vis[]){
    vis[node] = 1 ;
    for(auto adjNode:adj[node]){
        if(!vis[adjNode]){
            if(detectCycleDFS(adjNode,node,adj,V,vis) == true) return true ;
        }
        else if(adjNode != parent) return true ;
    }
    return false ;
}
  
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        if(vis[i] == 0){
            if(detectCycleDFS(i,-1,adj,V,vis)) return true ;
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
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
