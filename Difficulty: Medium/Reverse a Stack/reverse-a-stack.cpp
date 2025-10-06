class Solution {
  public:
    void insert(stack<int> &st, int element){
        if(st.empty()){
            st.push(element);
            return;
        }
        
        int newel= st.top();
        st.pop();
        
        insert(st, element);
        st.push(newel);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        
        int num = st.top();
        st.pop();
        
        reverseStack(st);
        insert(st, num);
    }
};