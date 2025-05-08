//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(int i, int j, int n, int m, vector<vector<int>>& arr, vector<string>&ans,
                vector<vector<int>>&vis, string path){
            if(i == n-1 && j == m-1){
                ans.push_back(path);
                return;
            }
            //UP
            if(i-1 >= 0 && arr[i-1][j] == 1 && vis[i-1][j] == 0){
                vis[i][j] = 1;
                solve(i-1,j,n,m,arr,ans,vis,path+'U');
                vis[i][j] = 0;
            }
            // DOWN
            if(i+1 < n && arr[i+1][j] == 1 && vis[i+1][j] == 0){
                vis[i][j] = 1;
                solve(i+1,j,n,m,arr,ans,vis,path+'D');
                vis[i][j] = 0;
            }
            // LEFT
            if(j-1 >= 0 && arr[i][j-1] == 1 && vis[i][j-1] == 0){
                // initially checking if the move is safe or not is backtracking
                vis[i][j] = 1;
                solve(i,j-1,n,m,arr,ans,vis,path+'L');
                // undo some step is back tracking
                vis[i][j] = 0;
            }
            // RIGHT
            if(j+1 < n && arr[i][j+1] == 1 && vis[i][j+1] == 0){
                vis[i][j] = 1;
                solve(i,j+1,n,m,arr,ans,vis,path+'R');
                vis[i][j] = 0;
            }
    }
    vector<string> ratInMaze(vector<vector<int>>& arr) {
        // code here
        vector<string>ans;
        string path = "";
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(arr[0][0] == 0 || arr[n-1][m-1] == 0) return ans;
            
        solve(0,0,n,m,arr,ans,vis,path);
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        vector<string> result = obj.ratInMaze(mat);
        // sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends