// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

#include<bits/stdc++.h>
using namespace std;

int timer = 0 ;

void dfs(int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> &mark,vector<int> adj[]){
    vis[node] = 1 ;
    tin[node] = low[node] = timer ;
    timer++ ;
    int child = 0 ;
    for(auto it:adj[node]){
        if(it == parent) continue ;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,mark,adj) ;
            low[node] = min(low[node] , low[it]) ;
            if(low[it] >= tin[node] && parent != -1) mark[node] = 1 ;
            child++ ;
        }
        else low[node] = min(low[node] , tin[it]) ;
    }
    if(child > 1 && parent == -1) mark[node] = 1 ;
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    // Code here
    vector<int> vis(V,0) ;
    int tin[V] ;
    int low[V] ;
    // MARK THE ARTICULATION POINTS
    vector<int> mark(V,0) ;
    // FOR MULTIPLE COMPONENTS
    for(int i=0 ; i<V ; i++){
        if(!vis[i]) dfs(i,-1,vis,tin,low,mark,adj) ;
    }
    vector<int> ans ;
    for(int i=0 ; i<V ; i++){
        // IF THE NODE IS MARKED AS ARTICULATION POINT
        if(mark[i] == 1) ans.emplace_back(i) ;
    }
    if(ans.size() == 0) return {-1} ;
    else return ans ;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans = articulationPoints(V, adj);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}
