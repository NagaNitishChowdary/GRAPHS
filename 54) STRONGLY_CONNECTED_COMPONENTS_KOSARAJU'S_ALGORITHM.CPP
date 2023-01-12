// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;
    
void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
    vis[node] = 1 ;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,adj,vis,st) ;
    }
    st.push(node) ;
}

void dfs1(int node,vector<int> adjT[],vector<int> &vis){
    vis[node] = 1 ;
    for(auto it:adjT[node]){
        if(!vis[it]) dfs1(it,adjT,vis) ;
    }
}

//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<int> adj[])
{
    //code here
    // STEP 1 --- SORT ALL THE EDGES ACCORDING TO THE FINISH TIME 
    stack<int> st ; // WHY STACK ? --- WE NEED TO STORE ALL 
                    // NODES ACCORDING TO THEIR FINISH TIME
    vector<int> vis(V,0) ;
    for(int i=0 ; i<V ; i++){
        if(!vis[i]) dfs(i,adj,vis,st) ;
    }
    
    // STEP 2 --- REVERSE THE GRAPH
    vector<int> adjT[V] ;
    for(int i=0 ; i<V ; i++){
        for(auto it:adj[i]){
            // i -> it 
            // it -> i 
            adjT[it].emplace_back(i) ;
        }
    }
    
    // STEP 3 --- PERFORM THE DFS ON THE ORDER OF FINISHING TIME 
    int scc = 0 ;
    for(int i=0 ; i<V ; i++) vis[i] = 0 ;
    while(!st.empty()){
        int node = st.top() ;
        st.pop() ;
        if(!vis[node]){
            scc++ ;
            dfs1(node,adjT,vis) ;
        }
    }
    
    return scc ;
}

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << kosaraju(V, adj) << "\n";
    }
    return 0;
}
