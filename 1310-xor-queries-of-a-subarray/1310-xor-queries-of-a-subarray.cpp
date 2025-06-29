class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;

        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i=1 ; i<n ; i++){
            prefix[i] = prefix[i-1] ^ arr[i];
        }

        for(auto i : queries){
            int l = i[0];
            int r = i[1];
            if(l == 0){
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[r] ^ prefix[l-1]);
            }
        }
        return ans;
        
    }
};