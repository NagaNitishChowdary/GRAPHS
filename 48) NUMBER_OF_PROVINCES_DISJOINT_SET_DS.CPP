// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces
// PROBLEM LINK --- https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

// CREATING DISJOINTSET DATA STRUCTURE 
class DisjointSet{
    public:
    vector<int> parent , rank , size ;
    // DECLARING PUBLIC ALL THE FUNCTIONS CAN BE USED OUTSIDE
    DisjointSet(int n){
        rank.resize(n+1,0) ;
        // N+1 IS AS WE ARE ASSUMING 1 BASED INDEXING 
        // AS 1 OR 0 BASED INDEXING N+1 WILL WORK
        parent.resize(n+1) ;
        size.resize(n+1) ;
        for(int i=0 ; i<=n ; i++){ parent[i] = i ; size[i] = 1 ; }
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

int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    DisjointSet ds(V) ;
    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            if(adj[i][j] == 1) ds.unionByRank(i,j) ; 
        }
    }
    
    int cnt = 0 ;
    for(int i=0 ; i<V ; i++){
       //  if(ds.findUPar(i) == i) cnt++ ;
       if(ds.parent[i] == i) cnt++ ;
    }
    
    return cnt ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << numProvinces(adj,V) << endl;
    }
    return 0;
}
