class Solution {
    int m, n;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n , -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0, q.push({i, j});
                }
            }
        } 
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0, 0, -1, 1};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first, j=p.second;
            for(int dir=0; dir<4;dir++){
                int ni = i  +dx[dir], nj = j + dy[dir];
                if(ni >= 0 && nj >=0 && ni < m && nj < n && dist[ni][nj] == -1){
                    dist[ni][nj] = dist[i][j] + 1 , q.push({ni, nj}); 
                }
            }
        }
        return dist;


    }
};