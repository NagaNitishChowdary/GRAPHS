// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

#include<bits/stdc++.h>
using namespace std ;

// USING KAHN'S ALGORITHM_TOPOLOGICAL_SORT_USING_BFS(QUEUE)

vector<int> topoSort(int V,vector<int> adj[]){
    int indegree[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        for(auto it:adj[i]) indegree[it]++ ;
    }
    
    queue<int> q;
    for(int i=0 ;i<V ; i++){
        if(indegree[i] == 0) q.push(i) ;
    }
    
    vector<int> topo ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topo.emplace_back(node) ;
        // NODE IS IN UR TOPO SORT 
        // SO PLEASE REMOVE IT FROM THE INDEGREE
        for(auto it:adj[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }
    return topo ;
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
        vector<int> knnc = topoSort(V,adj) ;
        for(auto it:knnc) cout << it << " " ;
        cout << endl ;
    }
    return 0 ;
}
