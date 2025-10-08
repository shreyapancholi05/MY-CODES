class Solution {
  public:
    void insertsorted(stack<int> &st, int n){
        if(st.empty() || st.top()<=n){
            st.push(n);
            return;
        }
        
        int num = st.top();
        st.pop();
        
        
        insertsorted(st, n);
        st.push(num);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();
        
        sortStack(st);
        insertsorted(st, num);
    }
};
