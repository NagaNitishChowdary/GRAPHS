// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal
// PROBLEM LINK --- https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/most-stones-removed-with-same-row-or-column_1376597

#include <bits/stdc++.h>
using namespace std;

// CREATING DISJOINTSET DATA STRUCTURE 
class DisjointSet{
    vector<int> parent , rank , size ;
public:
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

int maxRemove(vector<vector<int>>& stones, int n) {
    // Code here
    int maxRow = 0 , maxCol = 0 ;
    for(auto it:stones){
        maxRow = max(maxRow , it[0]) ;
        maxCol = max(maxCol , it[1]) ;
    }
    DisjointSet ds(maxRow + maxCol + 1) ;
    unordered_map<int,int> stoneNodes ;
    for(auto it:stones){
        int nodeRow = it[0] ;
        int nodeCol = it[1] + maxRow + 1 ;
        ds.unionBySize(nodeRow , nodeCol) ;
        stoneNodes[nodeRow]++ ;
        stoneNodes[nodeCol]++ ;
    }
    int cnt = 0 ;
    for(auto it:stoneNodes){
        if(ds.findUPar(it.first) == it.first) cnt++ ;
    }
    return n-cnt ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << maxRemove(adj, n) << "\n";
    }
}
