class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;

        unordered_set<int> mp1(nums1.begin(), nums1.end());
        unordered_set<int> mp2(nums2.begin(), nums2.end());
        
        vector<int> result1, result2;
        for(int x : mp1){
            if(mp2.find(x) == mp2.end()){
                result1.push_back(x);
            }
        }

        for(int x : mp2){
            if(mp1.find(x) == mp1.end()){
                result2.push_back(x);
            }
        }
        return {result1, result2};
    }
};