class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if(ch == '(' || ch == '+' || ch == '-'
                || ch == '*' || ch == '/'){
                    st.push(ch);
                }
            else if(ch == ')'){
                    bool isRedun = true;
                    
                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '+' || top == '-' || 
                            top == '*' || top == '/'){
                                isRedun = false;
                            }
                        st.pop();
                    }
                if(!st.empty()) st.pop();
                
                if(isRedun == true){
                    return true;
                
                }
            }
        }
        return false;
    }
};
