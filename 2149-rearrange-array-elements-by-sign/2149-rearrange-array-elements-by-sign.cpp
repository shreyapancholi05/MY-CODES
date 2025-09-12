class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int it : nums){
            if(it > 0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }

        vector<int> ans(nums.size());
        int i = 0, p = 0, n = 0;
        while(p < pos.size() && n < neg.size()){
            ans[i++] = pos[p++];
            ans[i++] = neg[n++];
        }

        while(p < pos.size()){
            ans[i++] = pos[p++];
        }

        while(n < neg.size()){
            ans[i++] = neg[n++];
        }
        return ans;
    }
};