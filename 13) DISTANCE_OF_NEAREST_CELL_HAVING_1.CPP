// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913
// PROBLEM LINK --- https://leetcode.com/problems/01-matrix/

#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<vector<int>> ans(n,vector<int>(m,0)) ;
    vector<vector<int>> vis(n,vector<int>(m,0)) ;
    queue<pair<pair<int,int>,int>> q ;
    // TC = O(N*M)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0}) ;
                vis[i][j] = 1 ;
            }
            else vis[i][j] = 0 ;
        }
    }
    int delRow[] = {-1,0,+1,0} ;
    int delCol[] = {0,+1,0,-1} ;
    // TC = O(N*M*4)
    while(!q.empty()){
        int row = q.front().first.first ;
        int col = q.front().first.second ;
        int steps = q.front().second ;
        q.pop() ;
        ans[row][col] = steps ;
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delRow[i] ;
            int ncol = col + delCol[i] ;
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1 ;
                q.push({{nrow,ncol},steps+1}) ;
            }
        }
    }
    return ans ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n,m ; cin >> n >> m ;
        vector<vector<int>> grid(n,vector<int>(m,0)) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cin >> grid[i][j] ;
        }
        vector<vector<int>> knnc = nearest(grid) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cout << knnc[i][j] << " " ;
            cout << endl ;    
        }
    }
    return 0 ;
}
