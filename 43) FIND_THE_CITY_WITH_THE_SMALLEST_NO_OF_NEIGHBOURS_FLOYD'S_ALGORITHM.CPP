// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
// PROBLEM LINK --- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance_1264289?leftPanelTab=0

// APPLICATION OF FLOYD'S ALGORITHM 

#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adjMatrix(n,vector<int>(n,1e9)) ;
    for(auto it:edges){
        // BIDIRECTIONAL
        adjMatrix[it[0]][it[1]] = it[2] ;
        adjMatrix[it[1]][it[0]] = it[2] ;
    }
    
    for(int i=0 ; i<n ; i++) adjMatrix[i][i] = 0 ;
    
    for(int via=0 ; via<n; via++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(adjMatrix[i][via] == INT_MAX || adjMatrix[via][j] == INT_MAX) continue ;
                adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][via] + adjMatrix[via][j]) ;
            }
        }
    }
    
    int cntCity = n ;
    int cityNo = -1 ;
    for(int city = 0 ; city<n ; city++){
        int cnt = 0 ;
        for(int adjCity = 0 ; adjCity<n ; adjCity++){
            if(adjMatrix[city][adjCity] <= distanceThreshold) cnt++ ;
        }
        if(cnt <= cntCity){
            cntCity = cnt ;
            cityNo = city ;
        }
    }
    
    return cityNo ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        cout << findCity(n, m, adj, dist) << "\n";
    }
}
