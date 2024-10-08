// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
// PROBLEM LINK --- https://leetcode.com/problems/shortest-path-in-binary-matrix/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/shortest-path-in-a-binary-maze_893065

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination) {
    // code here
    if(grid[destination.first][destination.second] == 0) return -1 ;
    if(source.first == destination.first && source.second == destination.second) return 0 ;
    // IN QUEUE ( { DIST , {ROW , COL} })
    queue<pair<int,pair<int,int>>> q ;
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<vector<int>> dist(n,vector<int>(m,1e9)) ;
    dist[source.first][source.second] = 0 ;
    q.push({0,{source.first,source.second}}) ;
    int drow[] = {-1,0,1,0} ;
    int dcol[] = {0,1,0,-1} ;
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        int dis = it.first ;
        int row = it.second.first ;
        int col = it.second.second ;
        
        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
            grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]){
                dist[nrow][ncol] = dis + 1 ;
                q.push({dis + 1 ,{nrow , ncol}}) ;
                if(nrow == destination.first && ncol == destination.second) return dis+1 ;
            }
        }
    }
    return -1 ;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        cout << shortestPath(grid, source, destination) << endl;
    }
}
