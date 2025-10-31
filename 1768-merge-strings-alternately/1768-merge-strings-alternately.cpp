class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string result = "";
        int i = 0, j=0;
        while(i<n && j<m){
            result += word1[i++];
            result += word2[j++];
        }

        if(i < n) result += word1.substr(i);
        if(j < m) result += word2.substr(j);

        return result;
    }
};