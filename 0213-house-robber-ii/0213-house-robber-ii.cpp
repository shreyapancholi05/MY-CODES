class Solution {
    int maxprofit(vector<int> &nums){
        int n = nums.size();
        vector<int> profit(n , 0);

        if(n == 1)
            return nums[0];
        profit[0] = nums[0];
        profit[1] = max(nums[0] , nums[1]);

        for(int i=2; i<n; i++){
            int rob = nums[i] + profit[i-2];
            int notrob = profit[i-1];

            profit[i] = max(rob , notrob);
         }
         return profit[n-1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int temp = nums.back();
        nums.pop_back();
        int profit1 = maxprofit(nums);
        nums.push_back(temp);
        nums.erase(nums.begin());
        int profit2 = maxprofit(nums);
        return max(profit1 , profit2);
    }
};