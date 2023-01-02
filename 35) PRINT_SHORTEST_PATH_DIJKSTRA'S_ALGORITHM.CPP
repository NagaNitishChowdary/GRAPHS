// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<pair<int,int>> adj[n+1] ;
    vector<int> path(n+1) ;
    for(int i=1 ; i<=n ; i++) path[i] = i ; 
    vector<int> dist(n+1,1e9) ;
    dist[1] = 0 ; 
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]}) ;
        adj[it[1]].push_back({it[0],it[2]}) ; 
    }
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    pq.push({0,1}) ;
    while(!pq.empty()){
        auto it = pq.top() ;
        int node = it.second ;
        int dis = it.first ;
        pq.pop() ;
        for(auto it1:adj[node]){
            int adjNode = it1.first ;
            int edgeDist = it1.second ;
            if(dist[adjNode] > dis + edgeDist){
                dist[adjNode] = dis + edgeDist ;
                pq.push({dist[adjNode] , adjNode}) ;
                path[adjNode] = node ;
            }
        }
    }
    if(dist[n] == 1e9) return {-1} ;
    vector<int> ans ;
    int node = n ;
    while(path[node] != node){
        ans.emplace_back(node) ;
        node = path[node] ;
    }
    ans.emplace_back(1) ;
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        vector<int> res = shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
