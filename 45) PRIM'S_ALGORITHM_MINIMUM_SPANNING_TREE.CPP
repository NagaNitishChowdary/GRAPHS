// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
    vector<int> vis(V,0) ;
    // HERE WE ONLY NEED TO RETURN THE SUM OF EDGES SO NO NEED TO CARRY PARENT 
    pq.push({0,0}) ;
    // PRIORITY_QUEUE { WEIGHT , NODE }
    int sumi = 0 ;
    while(!pq.empty()){
        auto it = pq.top() ;
        int wt = it.first ;
        int node = it.second ;
        pq.pop() ;
        // IF IT IS ALREADY VISITED
        if(vis[node] == 1) continue ;
        // WE MARK AS VISITED WHEN ONLY ADDED TO MST 
        vis[node] = 1 ;
        sumi += wt ;
        for(auto it:adj[node]){
            int adjNode = it[0] ;
            int edgeWt = it[1] ;
            if(!vis[adjNode]){
                pq.push({edgeWt , adjNode}) ;
            }
        }
    }
    return sumi ;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}
