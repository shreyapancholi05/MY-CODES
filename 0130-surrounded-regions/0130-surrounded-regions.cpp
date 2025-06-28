class Solution {
       int m; 
       int n;
    void dfs(int i, int j, vector<vector<char>> &board, int m , int n){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != 'O') return;
        board[i][j] = 'Y';
        dfs(i+1,j,board,m,n);
        dfs(i-1,j,board,m,n);
        dfs(i,j+1,board,m,n);
        dfs(i,j-1,board,m,n);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j] == 'O')
                        dfs(i, j, board,m,n);
                }  
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
                else{
                     board[i][j] = 'X';
                }
            }
        }
    }
};