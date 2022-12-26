// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
// PROBLEM LINK --- https://leetcode.com/problems/find-eventual-safe-states/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/library/find-eventual-safe-states

#include<bits/stdc++.h>
using namespace std ;

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> adjRev[V] ;
    int indegree[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        // i -> it
        // it -> i
        for(auto it:adj[i]){
            adjRev[it].push_back(i) ;
            indegree[i]++ ;
        }
    }
    queue<int> q ;
    vector<int> safeNodes ;
    for(int i=0 ; i<V ;i++){
        if(indegree[i] == 0) q.push(i) ;
    }
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        safeNodes.push_back(node) ;
        for(auto it:adjRev[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }
    sort(safeNodes.begin() , safeNodes.end()) ;
    return safeNodes ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int V,m ; cin >> V >> m ;
        vector<int> adj[V] ; 
        for(int i=0 ; i<m ; i++){
            int a,b ;
            cin >> a>> b ;
            adj[a].emplace_back(b) ;
        }
        vector<int> knnc = eventualSafeNodes(V,adj) ;
        for(auto it:knnc) cout << it << " " ;
        cout << endl ;
    }
    return 0 ;
}
