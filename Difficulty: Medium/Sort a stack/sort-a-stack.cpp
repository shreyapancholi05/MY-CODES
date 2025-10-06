class Solution {
  public:
    void insertsorted(stack<int> &st, int element){
        if(st.empty() || st.top() <= element){
            st.push(element);
            return;
        }
        
        int newel = st.top();
        st.pop();
        
        insertsorted(st, element);
        
        st.push(newel);
        
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
