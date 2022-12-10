// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
// PROBLEM LINK --- https://leetcode.com/problems/surrounded-regions/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/replace-o-with-x_630517?leftPanelTab=0



#include<bits/stdc++.h>
using namespace std ;

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,int delRow[],int delCol[],int n,int m){
    vis[row][col] = 1 ;
    for(int i=0 ; i<4 ; i++){
        int nrow = row + delRow[i] ;
        int ncol = col + delCol[i] ;
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O'){
            dfs(nrow,ncol,vis,mat,delRow,delCol,n,m) ;
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    vector<vector<int>> vis(n,vector<int>(m,0)) ;
    vector<vector<char>> ans = mat ;
    int delRow[] = {-1,0,+1,0} ;
    int delCol[] = {0,+1,0,-1} ;
    for(int i=0 ; i<m ; i++){
        if(mat[0][i] == 'O' && !vis[0][i]){
            dfs(0,i,vis,mat,delRow,delCol,n,m) ;
        }
    }
    for(int i=0 ; i<n ; i++){
        if(mat[i][0] == 'O' && !vis[i][0]){
            dfs(i,0,vis,mat,delRow,delCol,n,m) ;
        }
    }
    for(int i=0 ; i<m ; i++){
        if(mat[n-1][i] == 'O' && !vis[n-1][i]){
            dfs(n-1,i,vis,mat,delRow,delCol,n,m) ;
        }
    }
    for(int i=0 ; i<n ; i++){
        if(mat[i][m-1] == 'O' && !vis[i][m-1]){
            dfs(i,m-1,vis,mat,delRow,delCol,n,m) ;
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == 'O' && vis[i][j] == 0) ans[i][j] = 'X' ;
        }
    }
    return ans ;
}

int main()
{
    int n,m ; 
    cin >> n >> m ;
    vector<vector<char>> mat(n,vector<char>(m)) ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin >> mat[i][j] ;
    }
    vector<vector<char>> knnc = fill(n,m,mat) ;
    for(auto it:knnc){
        for(auto vctr:it) cout << vctr << " " ;
        cout << endl ;
    }
}
