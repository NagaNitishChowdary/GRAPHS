// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj1[],int vis[]){
    vis[node] = 1 ;
    for(auto it:adj1[node]){
        if(!vis[it]) dfs(it,adj1,vis) ;
    }
}

int numProvinces(vector<vector<int>> adj, int V) {

    // TO CHANGE ADJACENCY MATRIX TO LIST 
    vector<int> adj1[V] ;
    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<V ; j++){
            if(adj[i][j] == 1 && i != j){
                adj1[i].emplace_back(j) ;
                adj1[j].emplace_back(i) ;
            }
        }
    }

    int vis[V] = {0} ;
    int ans = 0 ;
    for(int i=0 ; i<V ; i++){
        if(vis[i] == 0){
            ans++ ;
            dfs(i,adj1,vis) ;
        }
    }
    return ans ;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        
        cout << numProvinces(adj,V) << endl;
    }
    return 0;
}
