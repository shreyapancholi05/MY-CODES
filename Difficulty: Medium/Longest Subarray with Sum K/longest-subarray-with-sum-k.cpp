class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int prefiSum = 0;
        int maxlen = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<arr.size(); i++){
            prefiSum += arr[i];
            
            if(prefiSum == k){
                maxlen = i+1;
            }
            
            else if(mp.find(prefiSum - k) != mp.end()){
                maxlen = max(maxlen, i - mp[prefiSum - k]);
            }
            
            if(mp.find(prefiSum) == mp.end()){
                mp[prefiSum] = i;
            }
        }
        
        return maxlen;
    }
};