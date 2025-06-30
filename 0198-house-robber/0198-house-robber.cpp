class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> profit(n, 0);

        profit[0] = nums[0];

        profit[1] = max(nums[0] , nums[1]);

        for(int i = 2; i<n; i++){
            int rob = nums[i] + profit[i-2];
            int notrob = profit[i-1];
            profit[i] = max(rob, notrob);
        }

        return profit[n-1];
    }
};