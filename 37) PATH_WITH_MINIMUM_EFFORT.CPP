// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/path-with-minimum-effort_1380958?leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>>& heights) {
    // Code here
    int n = heights.size() ;
    int m = heights[0].size() ;
    
    vector<vector<int>> dist(n,vector<int>(m,1e9)) ;
    dist[0][0] = 0 ;
    
    priority_queue< pair<int,pair<int,int>> , 
    vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq ;
    pq.push({0,{0,0}}) ;
    
    int drow[] = {-1,0,1,0} ;
    int dcol[] = {0,1,0,-1} ;
    
    while(!pq.empty()){
        auto it = pq.top() ;
        pq.pop() ;
        int diff = it.first ;
        int row = it.second.first ;
        int col = it.second.second ;
        
        if(row == n-1 && col == m-1) return diff ;
        
        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]) , diff) ;
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort ;
                    pq.push({newEffort,{nrow,ncol}}) ;
                }
            }
        }
    }
    return 0 ;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
        cout<< MinimumEffort(heights)<<"\n";
    }
    return 0;
}
