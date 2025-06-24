class Solution {
private:
    int atmost(vector<int>& nums, int k){
    int beg=0;
        int e = 0;
        int odd = 0;
        int ans = 0;

        while(e<nums.size()){
            if(nums[e] % 2 != 0)
                odd++;
        
        while(odd>k){
            if(nums[beg++] % 2 != 0)
                odd--;
        }
        ans = ans + (e-beg+1);
        e++;
        }
        return ans;
    }
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};