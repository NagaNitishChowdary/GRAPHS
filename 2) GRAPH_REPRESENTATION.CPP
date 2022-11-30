#include <bits/stdc++.h>
using namespace std;

// GRAPHS CAN BE STORED IN TWO WAYS 
// 1 --- MATRIX 
// 2 --- ADJACENCY LIST(IN CPP---VECTOR)

int main() {
    int n,m ;
    cin >> n >> m ;
    // USING ADJACENCY MATRIX 
    /*
    int matrix[n+1][n+1] = {0};
    for(int i=0 ; i<m ; i++){
        int u,v ;
        cin >> u >> v ;
        // FOR UNDIRECTED GRAPH
        matrix[u][v] = 1 ;
        matrix[v][u] = 1 ;

        // FOR DIRECTED GRAPH
        // matrix[u][v] = 1 ;

        // FOR WEIGHTED GRAPH INSTEAD OF STORING 1 STORE WEIGHT
    }     
    for(int i=1 ;i<=n ;i++){
        for(int j=1 ; j<=m ; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
     }
    */

    // USING ADJACENCY LIST ( EFFICIENT WAY ) 
    // FOR DIRECTED GRAPH SPACE CONSUMING O(E)
    // FOR UNDIRECTED GRAPH SPACE CONSUMING O(2*E)
    vector<int> adj[n+1] ;
    for(int i=0 ; i<m ;i++){
        int u,v ;
        cin >> u >> v ;
        // FOR UNDIRECTED GRAPH
        adj[u].emplace_back(v) ;
        adj[v].emplace_back(u) ;

        // FOR DIRECTED GRAPH
        // adj[u].emplace_back(v) ;

        // FOR WEIGHTED GRAPH STORE THE NODE AND WEIGHT IN PAIRS 
    }
    for(auto it:adj){
        for(auto knnc:it){
            cout << knnc << " " ;
        }
        cout << endl;
    }
}
