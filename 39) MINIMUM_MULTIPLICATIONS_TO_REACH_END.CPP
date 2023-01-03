// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    vector<int> dist(100000,1e9) ;
    dist[start] = 0 ;
    
    queue< pair<int,int>> q ;
    // QUEUE < STEPS , NODE > 
    q.push({0,start}) ;
    
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        
        int node = it.second ;
        int steps = it.first ;
        
        for(auto it:arr){
            int newNode = (node * it)%100000 ;
            if(steps + 1 < dist[newNode]){
                dist[newNode] = steps + 1 ;
                q.push({steps+1,newNode}) ;
                if(newNode == end) return steps + 1 ;
            }
        }
    }
    
    return -1 ;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        cout << minimumMultiplications(arr, start, end) << endl;
    }
}
