class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n, 0);

        int count = 0;
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> freqmap;
        for(int j =0; j<n; j++){
            if(prefix[j] == k){
                count++;
            }

            int val = prefix[j] - k;
            if(freqmap.find(val) != freqmap.end()){
                count += freqmap[val];
            }

            if(freqmap.find(prefix[j]) == freqmap.end()){
                freqmap[prefix[j]] = 0;
            }
            freqmap[prefix[j]]++;
        }
        return count;
    }
};