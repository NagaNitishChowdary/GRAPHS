// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// PROBLEM LINK --- https://leetcode.com/problems/is-graph-bipartite/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/check-graph-is-bipartite-or-not_920551

#include<bits/stdc++.h>
using namespace std ;

// COLORS A COMPONENT
bool check(int start,int V,vector<int> adj[],int col[]){
    col[start] = 0 ;
    queue<int> q ;
    q.push(start) ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        for(auto it:adj[node]){
            // IF THE ADJACENT NODE IS YET NOT COLOURED 
            // U WILL GIVE THE OPPOSITE COLOR OF THE NODE
            if(col[it] == -1){
                col[it] = !col[node] ;
                q.push(it) ;
            }
            // IS THE ADJACENT GUY HAVING THE SAME COLOR 
            // SOME ONE DID COLOR IT ON SOME OTHER PATH 
            else if(col[it] == col[node]) return false ;
        }
    }
    return true ;
}

bool isBipartite(int V, vector<int>adj[]){
    // Code here
    int col[V] ;
    for(int i=0 ; i<V ; i++) col[i] = -1 ;
    for(int i=0 ; i<V ; i++){
        if(col[i] == -1){
            if(check(i,V,adj,col) == false) return false ;
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
