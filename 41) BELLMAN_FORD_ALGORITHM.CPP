// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm
// PROBLEM LINK --- https://leetcode.com/problems/network-delay-time/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977

#include <bits/stdc++.h>
using namespace std;

/*  Function to implement Bellman Ford
*   edges: vector of vectors which represents the graph
*   S: source vertex to start traversing graph with
*   V: number of vertices
*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector<int> dist(V,1e8) ;
    dist[S] = 0 ;
    for(int i=0 ; i<V-1 ; i++){
        for(auto it:edges){
            int u = it[0] ;
            int v = it[1] ;
            int wt = it[2] ;
            // IF THE NODE IS REACHABLE 
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt ;
            }
        }
    }
    
    // IN QUESTION ALSO GIVEN IF GRAPH CONTAINS NEGATIVE CYCLE
    // RETURN AN ARRAY CONSISTING OF ONLY -1 
    
    // NTH RELAXATION TO CHECK NEGATIVE CYCLE 
    for(auto it:edges){
        int u = it[0] ;
        int v = it[1] ;
        int wt = it[2] ;
        // IF THE NODE IS REACHABLE 
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            return {-1} ;
        }
    }
    
    return dist ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;
        vector<int> res = bellman_ford(N, edges, src);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
