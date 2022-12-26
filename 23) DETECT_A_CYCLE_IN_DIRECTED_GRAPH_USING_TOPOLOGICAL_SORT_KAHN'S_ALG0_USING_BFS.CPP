// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include<bits/stdc++.h>
using namespace std ;

// DETECT CYCLE IN DIRECTED GRAPH USING TOPOLOGICAL SORT KAHN'S ALGORITHM
bool isCyclic(int V,vector<int> adj[]){
    // USING BFS
    int indegree[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        for(auto it:adj[i]) indegree[it]++ ;
    }
    
    queue<int> q ;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0) q.push(i) ;
    }
    
    // IN PLACE OF VECTOR USE COUNT VARIABLE 
    vector<int> topo ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topo.emplace_back(node) ;
        for(auto it:adj[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }
    
    if(topo.size() == V) return false ;
    else return true ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int m,V ; cin >> m >> V ;
        vector<int> adj[V] ;
        for(int i=0 ; i<m ; i++){
            int a,b ;
            cin >> a>> b ;
            adj[a].emplace_back(b) ;
        }
        cout << isCyclic(V,adj) << endl ;
    }
    return 0 ;
}
