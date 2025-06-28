class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>> q;
        int time = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 if(grid[i][j] == 2){
                    q.push({i , j});
                 }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int k =0 ; k < sz; k++){
                pair<int , int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                vector<int> dx = {0, 0, -1, 1}, dy = {-1, 1, 0 , 0};
                for(int dir = 0; dir<4 ; dir++){
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1){
                        q.push({ni , nj});
                        grid[ni][nj] = 2;
                    }
                }
                
            }
            time++;
        }
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time == 0 ? 0 : time - 1;

    }
};