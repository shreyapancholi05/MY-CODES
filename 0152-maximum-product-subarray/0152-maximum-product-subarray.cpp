class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int curr = nums[0];

        for(int i = 1; i<nums.size(); i++){
            curr *= nums[i];
            maxprod = max(maxprod, curr);

        
        }
        return maxprod;
    }
};