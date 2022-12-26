// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/topological-sort_985252

#include<bits/stdc++.h>
using namespace std ;

void dfs(int node,vector<int> adj[],stack<int> &st,int vis[]){
    vis[node] = 1 ;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,adj,st,vis) ;
    }
    st.push(node) ;
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    int vis[V] = {0} ;
    stack<int> st ;
    for(int i=0 ; i<V ; i++){
        if(!vis[i]) dfs(i,adj,st,vis) ;
    }
    vector<int> ans ;
    while(!st.empty()){ ans.emplace_back(st.top()) ;
    st.pop() ; }
    return ans ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int m,V ; cin >> m >> V ;
        vector<int> adj[V] ;
        for(int i=0 ; i<m ; i++){
            int a,b ;
            cin >> a>> b ;
            adj[a].emplace_back(b) ;
        }
        vector<int> knnc = topoSort(V,adj) ;
        for(auto it:knnc) cout << it << " " ;
        cout << endl ;
    }
    return 0 ;
}
