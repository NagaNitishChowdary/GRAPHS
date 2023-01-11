// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/number-of-islands-ii_1266048?leftPanelTab=0

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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    // code here
    DisjointSet ds(n*m) ;
    int vis[n][m] ;
    memset(vis , 0 ,sizeof(vis)) ; // IT FILLS ALL THE VIS WITH ZEROES
    int cnt = 0 ; // INITIALLY ISLANDS ARE ZERO 
    vector<int> ans ;
    for(auto it:operators){
        int row = it[0] ;
        int col = it[1] ;
        if(vis[row][col] == 1){
            ans.emplace_back(cnt) ;
            continue ;
        }
        // IF NOT VISITED
        vis[row][col] = 1 ;
        cnt++ ;
        // WE CHECK IN 4 DIRECTIONS
        // row-1 , col
        // row , col+1
        // row+1 , col 
        // row , col-1 
        int drow[] = {-1,0,1,0} ;
        int dcol[] = {0,1,0,-1} ;
        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                if(vis[nrow][ncol] ==  1){
                    int nodeNo = row * m + col ;
                    int adjNode = nrow * m + ncol ;
                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNode)){
                        cnt-- ;
                        ds.unionBySize(nodeNo , adjNode) ;
                    }
                }
            }
        }
        ans.emplace_back(cnt) ;
    }
    
    return ans ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        vector<int> res = numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}
