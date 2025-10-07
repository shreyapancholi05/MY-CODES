class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i=arr.size() - 1; i>=0; i--){
            int num = arr[i];
            while(st.top() >= num){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(num);
        }
        return ans;
    }
};