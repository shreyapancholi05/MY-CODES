class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result;

        for(int i=0; i<n; i++){
            int element = nums1[i]; 

            int next = -1;
            int j = 0;
            while(j < m && nums2[j] != element){
                j++;
            }

            for(int k = j+1; k<m; k++){
                if(nums2[k] > element){
                    next = nums2[k];
                    break;
                }
            }
            result.push_back(next);

        }
        return result;
    }
};