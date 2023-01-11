// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group
// PROBLEM LINK --- https://leetcode.com/problems/making-a-large-island/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/making-the-largest-island_1381282

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    unordered_map<int, int> size;
    
    DSU(int n)
    {
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    
    int findPar(int i)
    {
        if(parent[i] == i)
            return i;
        return parent[i] = findPar(parent[i]);
    }
    
    bool unionByRank(int a, int b)
    {
        int x = findPar(a), y = findPar(b);
        if(x == y) return false;
        
        if(rank[x] > rank[y]) parent[y] = x;
        else if(rank[x] < rank[y]) parent[x] = y;
        else
        {
            parent[x] = y;
            rank[x]++;
        }
        return true;
    }
    
    bool unionBySize(int a, int b)
    {
        int u = findPar(a), v = findPar(b);
        if(u == v) return false;
        
        if(size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else 
        {
            parent[v] = u;
            size[u] += size[v];
        }
        return true;
    }
};


bool isValid(int i, int j, int n, vector<vector<int>>& grid)
{
   return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j]);
}
    
int MaxConnection(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int maxi = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    DSU dsu(n * n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                int r = i, c = j;
                for(int k = 0; k < 4; k++)
                {
                    int newx = r+dx[k];
                    int newy = c+dy[k];
                    
                    // make union of all components
                    if(isValid(newx, newy, n, grid))
                    {
                        dsu.unionBySize(newx * n + newy, r * n + c);
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 0)
            {
                // to keep track of parents of neighbours of cell to be chnaged
                unordered_set<int> st;
                int res = 0, r = i, c = j;;
                
                for(int k = 0; k < 4; k++)
                {
                    int newx = r+dx[k];
                    int newy = c+dy[k];
                    
                    // if valid x, y => insert parent to the set
                    // set will store unique parents only thus 
                    // only unique components will be counted.
                    if(isValid(newx, newy, n, grid))
                    {
                        st.insert(dsu.findPar(newx * n + newy));
                    }
                }
                
                // we count the components in set and try to maximize it
                for(auto it: st)
                {
                    res += dsu.size[it];
                }
                maxi = max(maxi, res+1);
            }
        }
    }
   
   // in case all are ones
    for(int i = 0; i < n * n; i++) 
        maxi = max(maxi, dsu.size[dsu.findPar(i)]);

    return maxi;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        cout << MaxConnection(grid) << "\n" ;
    }
}
