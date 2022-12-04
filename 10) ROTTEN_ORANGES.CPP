// PROBLEM LINK --- https://leetcode.com/problems/rotting-oranges/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

#include<bits/stdc++.h>
using namespace std ;

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    queue<pair<pair<int,int>,int>> q ;
    int vis[n][m] ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0}) ;
                vis[i][j] = 2 ;
            }
            else vis[i][j] = 0 ;
        }
    }

    int time = 0 ;
    int delrow[] = {-1,0,+1,0} ;
    int delcol[] = {0,+1,0,-1} ;
    while(!q.empty()){
        int row = q.front().first.first ;
        int col = q.front().first.second ;
        int t = q.front().second ;
        time = max(time , t) ;
        q.pop() ;
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i] ;
            int ncol = col + delcol[i] ;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1}) ;
                vis[nrow][ncol] = 2 ;
            }
        }
    }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1 ) return -1 ;
            }
        }
    return time ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n,m ; cin >> n >> m ;
        vector<vector<int>> grid(n,vector<int>(m)) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cin >> grid[i][j] ;
        }
        cout << orangesRotting(grid) << endl ;
    }
    return 0 ;
}
