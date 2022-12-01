// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0} ; // VISITED ARRAY
    vis[0] = 1 ; // GIVEN TRAVERSAL STARTS FROM 0 
    queue<int> q ;
    q.push(0) ;
    vector<int> bfs ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        bfs.emplace_back(node) ;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1 ;
                q.push(it) ;
            }
        }
    }
    
    return bfs ;        
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int V, E;
        cin >> V >>E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 	adj[v].push_back(u); // HENCE THIS IS DIRECTED GRAPH
        }
        vector<int> ans = bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
