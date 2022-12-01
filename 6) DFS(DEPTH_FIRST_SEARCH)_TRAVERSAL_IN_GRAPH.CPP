// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

#include <bits/stdc++.h>
using namespace std;
  
void dfsTraversal(int node,vector<int> adj[],vector<int> &dfs,int vis[]){
    vis[node] = 1 ;
    dfs.emplace_back(node) ;
    // TRAVERSE ALL ITS NEIGHBOURS
    for(auto it:adj[node]){
        if(!vis[it]) dfsTraversal(it,adj,dfs,vis) ;
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int start = 0 ; // GIVEN STARTING FORM THE O TH VERTEX
    vector<int> dfs ;
    int vis[V] = {0} ;
    vis[0] = 1 ;
    dfsTraversal(start,adj,dfs,vis) ;
    return dfs ;
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
            // AS IT IS UNDIRECTED GRAPH
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans = dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
