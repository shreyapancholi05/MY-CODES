class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;

        for(int i=0; i<n; i++){
            int val = k - nums[i];

            if(mp[val] > 0){
                cnt++;
                mp[val]--;
            }
            else{
                mp[nums[i]]++;
            }
        }

        return cnt;
    }
};