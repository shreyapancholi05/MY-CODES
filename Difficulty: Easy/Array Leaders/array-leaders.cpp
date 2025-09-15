

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n = arr.size();
        ans.push_back(arr[n-1]);
        int j = 0;
        for(int i=n-2; i>=0; i--){
            if(arr[i] >= arr[i+1] && arr[i] >= ans[j]){
                ans.push_back(arr[i]);
                j++;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};