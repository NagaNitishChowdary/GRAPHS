// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/flloyd-warshall_2041979?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    // Code here
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] == -1) matrix[i][j] = 1e9 ;
            if(i == j) matrix[i][j] == 0 ;
        }
    }
    
    for(int via=0 ; via<n ; via++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]) ;
            }
        }
    }
    
    // HOW TO CHECK IF THERE IS A NEGATIVE CYCLE 
    for(int i=0 ; i<n ; i++){
        if(matrix[i][i] < 0){
            // THEN THERE IS A NEGATIVE CYCLE 
        }
    }
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] == 1e9) matrix[i][j] = -1 ;
        }
    }
    
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        shortest_distance(matrix);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
