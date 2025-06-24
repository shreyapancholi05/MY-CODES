class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int beg = 0;
        int end = 0;
        int flips = 0;
        int ans = 0;

        while (end < nums.size()) {
            if (nums[end] == 0) {
                flips++;
            }
            while (flips > k) {
                if (nums[beg] == 0)
                    flips--;
                beg++;
            }
            end++;
        ans = max(ans, end - beg);
        }
        return ans;
    }
    

};