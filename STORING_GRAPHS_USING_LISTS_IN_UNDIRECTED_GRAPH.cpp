//BY USING ADJACENCY LISTS(ARRAY OF VECTORS) WE CAN MAKE WITH VERY LESS
//SPACE COMPLEXITY(2*EDGES) IN UNDIRECTED GRAPHS

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    //n if index starts with 0
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n+1;i++){
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
