// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination
// PROBLEM LINK --- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    // code here
    // APPLICATION OF DIJKISTRA'S ALGORITHM
    
    // CONVERT ROADS INTO GRAPH 
    vector<pair<int,int>> adj[n] ;
    for(auto it:roads){
        // GIVEN BIDIRECTIONAL SO IT IS UNDIRECTED
        adj[it[0]].push_back({it[1],it[2]}) ;
        adj[it[1]].push_back({it[0],it[2]}) ;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
    pq.push({0,0}) ;
    // PRIORITY QUEUE < DIST , NODE > 
    
    vector<int> dist(n,1e9) ;
    dist[0] = 0 ;
    
    vector<int> ways(n,0) ;
    ways[0] = 1 ; // INITIALLY 
    int mod = (int)(1e9+7) ;
    
    while(!pq.empty()){
        // auto it = pq.top() ;
        // pq.pop() ;
        
        int node = pq.top().second ; // it.second ;
        int dis = pq.top().first ; // it.first ;
        pq.pop() ;
        
        for(auto it1:adj[node]){
            int adjNode = it1.first ;
            int edgWeight = it1.second ;
            // THIS IS THE FIRST TIME ARRIVING WITH SHORTEST DISTANCE
            if(dis + edgWeight < dist[adjNode]){
                dist[adjNode] = dis + edgWeight ;
                pq.push({dis + edgWeight , adjNode}) ;
                ways[adjNode] = ways[node] ;
            }
            else if(dis + edgWeight == dist[adjNode]){
                // NO NEED TO PUSH INTO QUEUE 
                // AS ONLY INCREMENTING THE PATH 
                // AS IT HAS THE MINIMAL PATH DISTANCE
                ways[adjNode] = (ways[adjNode] + ways[node])%mod ;
            }
        }
    }
    return ways[n-1]%mod ;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << countPaths(n, adj) << "\n";
    }

    return 0;
}
