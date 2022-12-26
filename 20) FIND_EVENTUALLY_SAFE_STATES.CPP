// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
// PROBLEM LINK --- https://leetcode.com/problems/find-eventual-safe-states/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/library/find-eventual-safe-states

// SAME AS THE DETECTING CYCLE USING DFS 
// IF THE NODE IS IN THE PART OF CYCLE THEN IT IS NOT THE SAFE NODE 
// AND THE NODE WHICH IS CONNECTED TO CYCLE THEN IT IS ALSO NOT THE SAFE NODE

#include<bits/stdc++.h>
using namespace std ;

bool dfs(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
    vis[node] = 1 ;
    pathVis[node] = 1 ;
    check[node] = 0 ;
    // TRAVERSE FOR ADJACENT NODES 
    for(auto it:adj[node]){
        // WHEN THE ROOT IS NOT VISITED
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis,check)){
                check[node] = 0 ;
                return true ;
            }
        }
        // IF THE NODE HAS BEEN PREVIOUSLY VISITED 
        // BUT IT HAS TO BE VISITED IN THE SAME PATH 
        else if(pathVis[it] == 1){
            check[node] = 0 ;
            return true ;
        }
    }
    check[node] = 1 ;
    pathVis[node] = 0 ;
    return false ;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    // code here
    vector<int> ans ;
    int vis[V] = {0} ;
    int pathVis[V] = {0} ;
    int check[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        if(!vis[i]) dfs(i,adj,vis,pathVis,check) ;
    }
    for(int i=0 ; i<V; i++){
        if(check[i]) ans.emplace_back(i) ;
    }
    return ans ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n,m ;
        cin >> n >> m ;
        vector<int> adj[n] ;
        int a , b ; 
        for(int i=0 ; i<m ; i++){
            cin >> a >> b ;
            adj[a].emplace_back(b) ;
            // adj[b].emplace_back(a) ; IT IS EXCLUDED BCZ IT IS DIRECTED GRAPH
        }
        vector<int> knnc = eventualSafeNodes(n,adj) ;
        for(auto it:knnc) cout << it << " " ;
        cout << endl ;
    }
}
