// CODE SNIPPET --- https://ide.geeksforgeeks.org/392f3f85-cb79-4631-9da2-3dd78e775873

#include<bits/stdc++.h>
using namespace std ;

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

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin) ;
    // freopen("input.txt","w",stdout) ;
    // #endif

    DisjointSet ds(7) ; // HERE 7 IS THE NUMBER OF NODES 
    ds.unionByRank(1,2) ;  // WE CAN USE RANK OR SIZE OUR WISH 
    ds.unionByRank(2,3) ;  // ds.unionBySize(2,3) ;
    ds.unionByRank(4,5) ;  // ds.unionBySize(2,3) ;
    ds.unionByRank(6,7) ;
    ds.unionByRank(5,6) ;
    // LETS CHECK IF 3 AND 7 ARE BELONGING TO THE SAME COMPONENT OR NOT 
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME" << endl ;
    else cout << "NOT SAME" << endl ;

    ds.unionByRank(3,7) ;
    // AFTER CONNECTING THEM NOW LETS CHECK 
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME" << endl ;
    else cout << "NOT SAME" << endl ;

    return 0 ;
}
