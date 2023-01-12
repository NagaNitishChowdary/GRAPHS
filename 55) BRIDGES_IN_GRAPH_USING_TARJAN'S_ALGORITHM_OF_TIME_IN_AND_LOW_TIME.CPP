// PROBLEM LINK --- https://leetcode.com/problems/critical-connections-in-a-network/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/critical-connections/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/critical-connection_1805503

#include<bits/stdc++.h>
using namespace std;

int timer = 1 ;

void dfs(int node , int parent ,vector<int> &vis,vector<int> adj[],int tin[],int low[],
        vector<vector<int>> &bridges){
    vis[node] = 1 ;
    tin[node] = low[node] = timer ;
    timer++ ;
    for(auto it:adj[node]){
        if(it == parent) continue ;
        if(vis[it] == 0){
            dfs(it,node,vis,adj,tin,low,bridges) ;
            low[node] = min(low[node] , low[it]) ;
            // CHECK FOR BRIDGE
            if(low[it] > tin[node]){
                vector<int> knnc ; 
                knnc.emplace_back(node) ; knnc.emplace_back(it) ;
                sort(knnc.begin() , knnc.end()) ;
             bridges.push_back(knnc) ; }
        }
        else{
            // IT CANNOT BE A BRIDGE
            low[node] = min(low[node] , low[it]) ;
        }
    }
}

vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
    // Code here
    // FOR DFS TRAVERSAL
    vector<int> vis(V,0) ;
    int tin[V] ;
    int low[V] ;
    vector<vector<int>> bridges ;
    dfs(0,-1,vis,adj,tin,low,bridges) ;
    sort(bridges.begin(),bridges.end()) ;
    return bridges ;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>ans = criticalConnections(V, adj);
        for(int i=0;i<ans.size();i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
