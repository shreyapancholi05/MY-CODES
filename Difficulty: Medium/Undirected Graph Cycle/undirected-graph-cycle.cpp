class Solution {
    bool cycle = false;
    void dfs(int curr , int src, vector<vector<int>> &adj, vector<int> &visited){
        visited[curr] = 1;
        for(int neighbour : adj[curr]){
            if(!visited[neighbour])
                dfs(neighbour , curr , adj , visited);
            else if(neighbour != src)
                cycle = true;
        }
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(V , 0);
        
        for(int i=0 ; i<V ; i++){
            if(!visited[i])
                dfs(i , -1, adj , visited);
        }
        return cycle;
    }
};