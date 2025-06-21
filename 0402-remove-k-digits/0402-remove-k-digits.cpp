class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> s;
        for(char i : num){
        while(!s.empty() && k>0 && s.top() > i){
            s.pop();
            k--;

        }
        s.push(i);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        string result;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin() , result.end());
        int start =0;
        while(start < result.size() && result[start] == '0'){
            start++;
        }
        result = result.substr(start);
        if(!result.empty()) return result;
        return "0";
    }
};