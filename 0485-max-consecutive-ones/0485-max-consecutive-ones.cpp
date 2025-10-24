class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int cnt = 0;

        for(int it : nums){
            if(it == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }

            if(cnt > maxi){
                maxi = cnt;
            }
        }

        return maxi;
    }
};