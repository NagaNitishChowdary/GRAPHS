// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/accounts-merge_1089558?leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/accounts-merge/

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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    // code here
    int n = accounts.size() ;
    DisjointSet ds(n) ;
    unordered_map< string , int > mpp ;
    for(int i=0 ; i<n ; i++){
        int size = accounts[i].size() ;
        for(int j=1 ; j<size ; j++){
            string mail = accounts[i][j] ;
            if(mpp.find(mail) == mpp.end()) mpp[mail] = i ;
            else{
                ds.unionBySize(i,mpp[mail]) ;
            }
        }
    }
    
    vector<string> mergedMail[n] ;
    for(auto it:mpp){
        string mail = it.first ;
        int node = ds.findUPar(it.second) ;
        mergedMail[node].push_back(mail) ;
    }
    
    vector<vector<string>> ans ;
    for(int i=0 ; i<n ; i++){
        if(mergedMail[i].size() == 0) continue ;
        vector<string> temp ;
        temp.emplace_back(accounts[i][0]) ;
        sort(mergedMail[i].begin() , mergedMail[i].end()) ;
        for(auto it:mergedMail[i]){
            temp.emplace_back(it) ;
        }
        ans.emplace_back(temp) ;
    }
    
    return ans ;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    vector<vector<string>> res = accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
