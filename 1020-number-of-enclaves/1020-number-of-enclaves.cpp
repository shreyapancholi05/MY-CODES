class Solution {
    vector<int> dx = {-1, 1, 0 , 0};
    vector<int> dy = {0, 0, -1, 1};
    void dfs(int i,int j, vector<vector<int>> &grid,int m, int n){
        if(i<0 || j<0 || i>=m || j>=n ||grid[i][j] == 0) 
            return;
        grid[i][j] = 0;
        /*
        dfs(i-1, j, grid, m, n);
        dfs(i+1 , j, grid, m, n);
        dfs(i ,j-1 ,grid, m, n);
        dfs(i, j+1 , grid, m ,n);
            */
        for(int dir=0; dir<4; dir++){
            dfs(i + dx[dir] , j + dy[dir] , grid, m, n);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i == 0 || j==0 || i == m-1 || j == n-1)
                    if(grid[i][j] == 1)
                        dfs(i ,j ,grid,m,n);
            
        int cnt = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    cnt++;
        return cnt;

    }
};