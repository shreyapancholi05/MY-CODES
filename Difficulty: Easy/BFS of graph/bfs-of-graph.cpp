class Solution {
  public:
    void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited,
                vector<int> &ans, int node){
    
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            for(auto it : adj[frontNode]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
    }
    // / Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        int n = adj.size();
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(adj, visited, ans,i);
            }
        }
        
        return ans;
    }
};