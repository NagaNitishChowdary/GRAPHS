// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
// PROBLEM LINK --- https://leetcode.com/problems/number-of-enclaves/

#include<bits/stdc++.h>
using namespace std ;

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[],int n,int m){
    vis[row][col] = 1 ;
    for(int i=0 ; i<4 ; i++){
        int nrow = row + delRow[i] ;
        int ncol = col + delCol[i] ;
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
            dfs(nrow,ncol,vis,grid,delRow,delCol,n,m) ;
        }
    }
}
  
int numberOfEnclaves(vector<vector<int>> &grid) {
    // Code here
    int n = grid.size() ;
    int m = grid[0].size() ;
    int ans = 0 ;
    vector<vector<int>> vis(n,vector<int>(m,0)) ;
    int delRow[] = {-1,0,+1,0} ;
    int delCol[] = {0,+1,0,-1} ;
    for(int i=0 ; i<m ; i++){
        if(grid[0][i] == 1 && !vis[0][i]){
            dfs(0,i,vis,grid,delRow,delCol,n,m) ;
        }

        if(grid[n-1][i] == 1 && !vis[n-1][i]){
            dfs(n-1,i,vis,grid,delRow,delCol,n,m) ;
        }
    }
    for(int i=0 ; i<n ; i++){
        if(grid[i][0] == 1 && !vis[i][0]){
            dfs(i,0,vis,grid,delRow,delCol,n,m) ;
        }
        
        if(grid[i][m-1] == 1 && !vis[i][m-1]){
            dfs(i,m-1,vis,grid,delRow,delCol,n,m) ;
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0) ans++  ;
        }
    }
    return ans ;
}

int main()
{
    int n,m ; 
    cin >> n >> m ;
    vector<vector<int>> grid(n,vector<int>(m)) ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin >> grid[i][j] ;
    }
    cout << numberOfEnclaves(grid) << endl ;
}
