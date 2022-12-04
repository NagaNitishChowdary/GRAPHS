// PROBLEM LINK --- https://leetcode.com/problems/flood-fill/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

#include<bits/stdc++.h>
using namespace std ;

void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,int color,int delRow[],int delCol[],int initialColor){
    ans[row][col] = color ;
    int n = image.size() ;
    int m = image[0].size() ;
    // CHECKING 4 NEIGHBOURS OF THE NODE ie UP RIGHT DOWN LEFT 
    for(int i=0 ; i<4 ; i++){
        int nrow = row + delRow[i] ;
        int ncol = col + delCol[i] ;
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != color){
            dfs(nrow,ncol,ans,image,color,delRow,delCol,initialColor) ;
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc] ;
    vector<vector<int>> ans = image ;
    int delRow[] = {-1,0,1,0} ;
    int delCol[] = {0,1,0,-1} ;
    dfs(sr,sc,ans,image,color,delRow,delCol,initialColor) ;
    return ans ;
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,m ; cin >> n >> m ;
        vector<vector<int>> image(n,vector<int>(m,0)) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cin >> image[i][j] ;
        }
        int startingRow,startingCol,newColor ;
        cin >> startingRow >> startingRow >> newColor ;
        vector<vector<int>> knnc = floodFill(image,startingRow,startingCol,newColor) ;
        for(auto vctr:knnc){
            for(auto it:vctr) cout << it << " " ;
            cout << endl ;    
        }
    }
} 
