class DSU {
    public:
    vector<int>par;
	vector<int>size;
    DSU(int n){
        par.resize(n);
        size.resize(n, 1);
    for(int i = 0; i < n; i++) par[i] = i;
    }
 
    int findParent(int x){
        if(par[x] == x) return x;
        return par[x] = findParent(par[x]);
    }
    
 
    bool unionSets(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)    return true;
        if(size[pu] > size[pv])
            par[pv] = pu, size[pu] += size[pv];
        else
            par[pu] = pv, size[pv] += size[pu];
        return false;
    }
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<int>> edges;
        for(int i = 0; i < V ; i++)
        {
            for(auto neigh : adj[i])
            {
                int wt = neigh[1];
                edges.push_back({wt , i, neigh[0]});
        }
    }
    sort(edges.begin() , edges.end());
    int ans = 0;
    DSU dsu(V + 1);
    for(auto e: edges){
        if(dsu.unionSets(e[1] , e[2]) == false)
            ans += e[0];

    }
        return ans;
    
    }
};