class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        int ans = high;

        while(low <= high){
            int mid = low+(high-low)/2;
            int total = 0;
            for(auto i : nums){
                total += ceil((double)i/mid);
            }     
            if(total <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
       }
       return ans;
    }
};