
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Your code here
        unordered_map<char , int> count;
        queue<char> q;
        // char ans = " ";
        
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            
            count[ch]++;
            q.push(ch);
            
            while(!q.empty() && count[q.front()]>1){

                    q.pop();
               
            }
        }
        if(!q.empty()){
            return q.front();
        }
        else{
            return '$';
            
        }
    }
};