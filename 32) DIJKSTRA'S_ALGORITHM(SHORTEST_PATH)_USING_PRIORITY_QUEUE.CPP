// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
// PROBLEM LINK --- https://leetcode.com/problems/network-delay-time/submissions/

#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    // WE TAKE MIN - HEAP IE PRIORITY QUEUE
    // priority_queue{dist,node}
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    vector<int> dist(V,1e9) ;
    dist[S] = 0 ;
    pq.push({0,S}) ;
    
    while(!pq.empty()){
        int dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;
        
        for(auto it:adj[node]){
            int edgeWeight = it[1] ;
            int adjNode = it[0] ;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight ;
                pq.push({dist[adjNode] , adjNode}) ;
            }
        }
    }
    for(int i=0 ; i<V ; i++){
        for(auto it:adj[i]){
            for(auto vctr:it) cout << vctr << " " ;
            cout << endl ;    
        }
    }

    return dist ;
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
        int S;
        cin>>S;
        vector<int> res = dijkstra(V, adj, S);
        
        for(int i=0; i<V; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}
