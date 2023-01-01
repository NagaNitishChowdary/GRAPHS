// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<int> adj[N] ;
    for(int i=0 ; i<M ; i++){
        int src = edges[i][0] ;
        int dest = edges[i][1] ;
        adj[src].emplace_back(dest) ;
        adj[dest].emplace_back(src) ;
    }
    
    // USING PURE BFS ALGORITHM 
    queue<pair<int,int>> q ;
    q.push({src,0}) ;
    vector<int> dist(N,1e9) ;
    dist[src] = 0 ;
    while(!q.empty()){
        auto it1 = q.front() ;
        q.pop() ;
        int node = it1.first ;
        int dist1 = it1.second ;
        for(auto it:adj[node]){
            if(dist[it] > dist1 + 1){
                dist[it] = dist1 + 1 ;
                q.push({it,dist1+1}) ;
            }
        }
    }
    for(int i=0 ; i<N ; i++){
        if(dist[i] == 1e9) dist[i] = -1 ;
    }
    return dist ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        int src; cin >> src;
        vector<int> res = shortestPath(edges, n, m, src);
        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
