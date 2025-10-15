class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
       int n = s.length();
       int maxlen = 0;
       int i=0; 
       int j = 0;

       while(j < n){
        if(st.find(s[j]) == st.end()){
            st.insert(s[j]);
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        else{
            st.erase(s[i]);
            i++;
        }
       }

       return maxlen;
       
    }
};