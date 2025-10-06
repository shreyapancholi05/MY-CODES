class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char> st;
        for(int i=0; i<S.length(); i++){
            char ch = S[i];
            st.push(ch);
        }
        
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            ans.push_back(ch);
            st.pop();
        }
        return ans;
    }
};