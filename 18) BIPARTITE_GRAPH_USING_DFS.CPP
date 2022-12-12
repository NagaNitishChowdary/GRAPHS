// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// PROBLEM LINK --- https://leetcode.com/problems/is-graph-bipartite/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/check-graph-is-bipartite-or-not_920551

#include<bits/stdc++.h>
using namespace std ;

// COLORS A COMPONENT
bool dfs(int node, int initcol, int col[], vector<int> adj[]) {
    col[node] = initcol; 
    
    // traverse adjacent nodes
    for(auto it : adj[node]) {
        // if uncoloured
        if(col[it] == -1) {
            if(dfs(it, !initcol, col, adj) == false) return false; 
        }
        // if previously coloured and have the same colour
        else if(col[it] == initcol) {
            return false; 
        }
    }
    
    return true; 
}

bool isBipartite(int V, vector<int>adj[]){
    // Code here
    int col[V] ;
    for(int i=0 ; i<V ; i++) col[i] = -1 ;
    for(int i=0 ; i<V ; i++){
        if(col[i] == -1){
            if(dfs(i,0,col,adj) == false) return false ;
        }
    }
    return true ;
}


int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n,m ; cin >> n >> m ;
        vector<int> adj[n] ;
        for(int i=0 ; i<m ; i++){
            int a,b ; cin >> a >> b  ;
            adj[a].push_back(b) ;
            adj[b].push_back(a) ;
        }
        if(isBipartite(n,adj)) cout << "TRUE" << "\n" ;
        else cout << "FALSE" << "\n" ;
    }
}
