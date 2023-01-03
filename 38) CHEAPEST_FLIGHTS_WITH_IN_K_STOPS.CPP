// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
// PROBLEM LINK --- https://leetcode.com/problems/cheapest-flights-within-k-stops/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/saving-money_1171195

#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    // Code here
    // APPLIATION OF DIJKSTRA'S ALGORITHM 
    // CONVERT THE GIVEN EDGES INTO GRAPH 
    vector<pair<int,int>> adj[n] ;
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]}) ;
    }
    queue<pair<int,pair<int,int>>> q ;
    // QUEUE< STOPS , NODE , DIST > 
    q.push({0,{src,0}}) ;
    
    vector<int> dist(n,1e9) ;
    dist[src] = 0 ;
    
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        
        int stops = it.first ;
        int node = it.second.first ;
        int dis = it.second.second ;
        if(stops > K) continue ;
        
        for(auto it:adj[node]){
            int adjNode = it.first ;
            int edgCost = it.second ;
            if(dis + edgCost <= dist[adjNode] && stops <= K){
                dist[adjNode] = dis + edgCost ;
                q.push({stops+1 , {adjNode , dist[adjNode]}}) ;
            }
            
        }
    }
    
    if(dist[dst] == 1e9) return -1 ;
    else return dist[dst] ;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        cout<<CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
