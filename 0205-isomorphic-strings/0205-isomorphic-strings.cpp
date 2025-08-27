class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,char> mp;
        unordered_map<char,char> pm;

        for(int i=0; i<s.length(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp.count(ch1)){
                if(mp[ch1] != ch2){
                    return false;
                }
            }
            else{
                mp[ch1] = ch2;
            }
            if(pm.count(ch2)){
                if(pm[ch2] != ch1){
                    return false;
                }
            }
        else{
            pm[ch2] = ch1;
        }
        }
        return true;
    }
};