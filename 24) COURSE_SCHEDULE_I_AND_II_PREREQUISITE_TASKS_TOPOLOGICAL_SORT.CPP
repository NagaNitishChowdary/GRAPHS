// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/prerequisite-task_982936

// PREREQUISITE TASK 

#include<bits/stdc++.h>
using namespace std ;

bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    // Code here
    vector<int> adj[N] ;
    for(auto it:prerequisites){
        adj[it.first].emplace_back(it.second) ;
    }
    int indegree[N] = {0} ;
    for(int i=0 ; i<N ; i++){
        for(auto it:adj[i]) indegree[it]++ ;
    }
    
    queue<int> q ;
    for(int i=0 ; i<N ; i++){
        if(indegree[i] == 0) q.push(i) ;
    }
    
    // IN PLACE OF VECTOR USE COUNT VARIABLE 
    vector<int> topo ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topo.emplace_back(node) ;
        for(auto it:adj[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }
    
    if(topo.size() == N) return true ;
    else return false ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int V,m ; cin >> V >> m ;
        vector<int> adj[V] ; 
        vector<pair<int, int> > prerequisites ;
        for(int i=0 ; i<m ; i++){
            int a,b ;
            cin >> a>> b ;
            pair<int,int> pr ;
            pr.first = a ; pr.second = b ;
            prerequisites.emplace_back(pr) ;
        }
        cout << isPossible(V,prerequisites) << endl ;
    }
    return 0 ;
}

// COURSE SCHEDULE I AND II 

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
  {
      //code here
      vector<int> adj[N] ;
      for(auto it:prerequisites){
          adj[it[1]].emplace_back(it[0]) ;
      }
      int indegree[N] = {0} ;
      for(int i=0 ; i<N ; i++){
          for(auto it:adj[i]) indegree[it]++ ;
      }

      queue<int> q ;
      for(int i=0 ; i<N ; i++){
          if(indegree[i] == 0) q.push(i) ;
      }

      // IN PLACE OF VECTOR USE COUNT VARIABLE 
      vector<int> topo ;
      while(!q.empty()){
          int node = q.front() ;
          q.pop() ;
          topo.emplace_back(node) ;
          for(auto it:adj[node]){
              indegree[it]-- ;
              if(indegree[it] == 0) q.push(it) ;
          }
      }

      if(topo.size() == N) return topo ;
      else return {} ;
  }
