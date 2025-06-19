class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxim = *max_element(nums.begin() , nums.end());
        int ans = 0;
        int count = 0;
        for(int i=0; i<nums.size() ; i++){
            if(nums[i] == maxim){
                count++;
                ans = max(ans, count);
            }
            else{
                count = 0;
                 
            }
        }
        return ans;
    }
};