class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxsum = nums[0];
        for(int i = 0; i<nums.size(); i++){
            curr += nums[i];
            if(curr < nums[i]){
                curr = nums[i];
            }

            maxsum = max(maxsum, curr);

        }
        return maxsum;
    }
};