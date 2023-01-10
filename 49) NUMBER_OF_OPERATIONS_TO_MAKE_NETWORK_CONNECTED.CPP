// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
// PROBLEM LINK --- 

// USING DFS --- CHECKING NO OF CONNECTED COMPONENTS

#include <bits/stdc++.h>
using namespace std;
 
void dfs(int node , int vis[] , vector<int> adj[]){
    vis[node] = 1 ;
    for(auto it:adj[node]){
        if(vis[it] == 0) dfs(it,vis,adj) ;
    }
}

int Solve(int n, vector<vector<int>>& edge) {
    // code here
    int m = edge.size() ;
    // FOR N VERTICES AT N-1 EDGES ARE NEEDED TO MAKE THE GRAPH INTO A SINGLE COMPONENT
    if(n-1 > m) return -1 ; 
    int vis[n] = {0} ;
    vector<int> adj[n] ;
    for(auto it:edge){
        int src = it[0] ;
        int dest = it[1] ;
        adj[src].emplace_back(dest) ;
        adj[dest].emplace_back(src) ;
    }
    
    int cnt = 0 ;
    for(int i=0 ; i<n ; i++){
        if(vis[i] == 0){
            dfs(i,vis,adj) ;
            cnt++ ;
        }
    }
    
    return cnt-1 ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << Solve(n, adj) << "\n";
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// USING DISJOINT SET DATA STRUCTURE 
    
class DisjointSet{
public:    
    vector<int> parent , rank , size ;
    //public:
    // DECLARING PUBLIC ALL THE FUNCTIONS CAN BE USED OUTSIDE
    DisjointSet(int n){
        rank.resize(n+1,0) ;
        // N+1 IS AS WE ARE ASSUMING 1 BASED INDEXING 
        // AS 1 OR 0 BASED INDEXING N+1 WILL WORK
        parent.resize(n+1) ;
        size.resize(n+1) ;
        for(int i=0 ; i<=n ; i++){ parent[i] = i ; size[i] = i ; }
    }

    // FUNCTION TO FIND ULTIMATE PARENT 
    int findUPar(int node){
        if(node == parent[node]) return node ;
        return parent[node] = findUPar(parent[node]) ;
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        // IF ULTIMATE PARENT OF U EQUALS TO THE ULTIMATE PARENT OF V
        // THIS MEANS THEY ARE BELONGING TO THE SAME COMPONENT
        if(ulp_u == ulp_v) return ; 
        // ELSE CASE 
        if(rank[ulp_u] < rank[ulp_v]){
            // THEN SMALLER RANK GOES AND ATTACHED TO THE BIGGER ONE 
            parent[ulp_u] = ulp_v ; // AND RANK DOES NOT CHANGES
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            // THEN SMALLER RANK GOES AND ATTACHED TO THE BIGGER ONE 
            parent[ulp_v] = ulp_u ; // AND RANK DOES NOT CHANGES
        }
        else{
            parent[ulp_v] = ulp_u ; // OR parent[ulp_u] = ulp_v ;
            // IF RANKS ARE EQUAL ANYONE CAN CONNECT TO ANYONE 
            rank[ulp_u]++ ;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        // IF ULTIMATE PARENT OF U EQUALS TO THE ULTIMATE PARENT OF V
        // THIS MEANS THEY ARE BELONGING TO THE SAME COMPONENT
        if(ulp_u == ulp_v) return ; 
        // ELSE NOW DOING COMPRESSION OF SIZE 
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ; 
            size[ulp_v] += size[ulp_u] ;
        }
        else{
            parent[ulp_v] = ulp_u ; 
            size[ulp_u] += size[ulp_v] ;        
        }
    }

};

int Solve(int n, vector<vector<int>>& edge) {
    int m = edge.size() ;
    if(n-1 > m) return -1 ;
    DisjointSet ds(n) ;
    // CREATING THE GRAPH
    for(auto it:edge){
        ds.unionByRank(it[0],it[1]) ;
    }
    
    int cnt = 0 ;
    for(int i=0 ; i<n ; i++){
        if(ds.parent[i] == i) cnt++ ;
    }
    return cnt - 1 ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << Solve(n, adj) << "\n";
    }
    return 0;
}
