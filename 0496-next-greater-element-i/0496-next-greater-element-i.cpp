class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int i=nums2.size()-1; i>=0; i--){
            int num = nums2[i];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(st.empty()){
                mp[num] = -1;
            }
            else{
                mp[num] = st.top();
            }
            st.push(num);
        }
        
        vector<int> result;
        for(int i=0; i<nums1.size(); i++){
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};