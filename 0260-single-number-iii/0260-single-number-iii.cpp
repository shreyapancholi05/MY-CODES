class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }

        ans = 1ll*ans & 1ll*(~(1ll*ans-1));
        int num1 =0;
        int num2 = 0;
        for(int i : nums){
            if(i & ans){
                num1 ^= i;
            }
            else{
                num2 ^= i;
            }
        }
        return {num1 , num2};
    }
};