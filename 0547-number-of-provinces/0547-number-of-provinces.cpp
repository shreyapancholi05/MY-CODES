
class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!= j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n ; i++){
            if(vis[i]) continue;
            count++;
            dfs(i, adj, vis);
        }

        return count;
    }
};