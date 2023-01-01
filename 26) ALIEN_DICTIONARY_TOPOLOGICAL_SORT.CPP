// PROBLEM LINK --- https://leetcode.com/problems/alien-dictionary/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/alien-dictionary_630423

#include<bits/stdc++.h>
using namespace std ;

vector<int> topoSort(int V , vector<int> adj[]){
    int indegree[V] = {0} ;
    for(int i=0 ; i<V ; i++){
        for(auto it:adj[i]) indegree[it]++ ;
    }
    queue<int> q ;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0) q.push(i) ;
    }
    vector<int> topo ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topo.emplace_back(node) ;
        // node is in ur topo sort
        // so please remove it from indegree
        for(auto it:adj[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }
    return topo ;
}

string findOrder(string dict[], int N, int K) {
    //code here
    vector<int> adj[K] ;
    for(int i=0 ; i<N-1 ; i++){
        string str1 = dict[i] ;
        string str2 = dict[i+1] ;
        int comparisionSize = min(str1.size() , str2.size()) ;
        for(int i=0 ; i<comparisionSize ; i++){
            if(str1[i] != str2[i]){
                // THEN CREATE AN DIRECTED EDGE
                adj[str1[i] - 'a'].emplace_back(str2[i] - 'a') ;
                break ;
            }
        }
    }
    vector<int> topo = topoSort(K,adj) ;
    string ans = "" ;
    for(auto it:topo) ans += char(it + 'a') ;
    return ans ;
}

int main()
{
	int testCases ; cin >> testCases ;
	while(testCases--){
		int N , K ;
		cin >> N >> K ;
        string dict[N] ;
        for(int i=0 ; i<N ; i++){
        	string str ;cin >> str ;
        	dict[i] = str ;
        }
        cout << findOrder(dict,N,K) << endl ;
	}
	return 0 ;
}
