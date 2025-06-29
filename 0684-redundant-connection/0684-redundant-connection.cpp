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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);
        for(int i=0 ; i< n; i++){
            if(dsu.unionSets(edges[i][0] , edges[i][1])){
                return edges[i];
            }
        }
        return {};
    }
};