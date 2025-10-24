class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int count=0;
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int>prefixfreq;
        for(int j=0; j<prefix.size(); j++){
            if(prefix[j] == k){
                count++;
            }
            int val = prefix[j] - k;
            if(prefixfreq.find(val) != prefixfreq.end()){
                count += prefixfreq[val];
            }
            prefixfreq[prefix[j]]++;
        }
        return count;
    }
};
