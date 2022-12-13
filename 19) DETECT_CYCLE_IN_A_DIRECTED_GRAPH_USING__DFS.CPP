// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std ;

bool dfs(int node,int vis[],int pathVis[],vector<int> adj[]){
    vis[node] = 1 ;
    pathVis[node] = 1 ;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,vis,pathVis,adj) == true) return true ; 
        }
        else if(pathVis[it] == 1) return true ;
        // else pathVis[it] = 0 ;
    }
    pathVis[node] = 0 ;
    return false ;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    int vis[V] = {0} ;
    int pathVis[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            if(dfs(i,vis,pathVis,adj) == true) return true ;
        }
    }
    return false ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int V,m ; cin >> V >> m ;
        vector<int> adj[V] ;
        for(int i=0 ; i<m ; i++){
            int a,b ; cin >> a >> b ;
            adj[a].push_back(b) ;
        }
        cout << isCyclic(V,adj) << endl ;
    }
    return 0 ;   
}
