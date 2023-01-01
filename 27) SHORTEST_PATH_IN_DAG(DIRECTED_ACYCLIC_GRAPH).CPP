// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph

#include <bits/stdc++.h>
using namespace std;

void topoSort(int node , vector<pair<int,int>> adj[] , stack<int> &st, vector<int> &vis){
    vis[node] = 1 ;
    for(auto it:adj[node]){
        if(!vis[it.first]) topoSort(it.first,adj,st,vis) ;
    }
    st.push(node) ;
} 

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here
    vector<pair<int,int>> adj[N] ;
    for(int i=0 ; i<M ; i++){
        int src = edges[i][0] ;
        int dest = edges[i][1] ;
        int dist = edges[i][2] ;
        adj[src].push_back({dest,dist}) ;
    }
    
    // STEP 1 --- FIND TOPO SORT USING DFS 
    // AND STORE IT IN STACK 
    
    stack<int> st ;
    vector<int> vis(N,0) ;
    for(int i=0 ; i<N ; i++){
        if(!vis[i]) topoSort(i,adj,st,vis) ;
    }
    
    // STEP 2 --- DO THE DISTANCE THING
    vector<int> dist(N,1e9) ;
    // ALWAYS SOURCE IS 0 
    dist[0] = 0 ;
    while(!st.empty()){
        int node = st.top() ;
        st.pop() ;
        for(auto it:adj[node]){
            int adjNode = it.first ;
            int dista = it.second ;
            if(dist[node] + dista < dist[adjNode]){
                dist[adjNode] = dist[node] + dista ;
            }
        }
    }
    
    for(int i=0 ; i<N ; i++){
        if(dist[i] == 1e9) dist[i] = -1 ;
    }
    return dist ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        vector<int> res = shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
