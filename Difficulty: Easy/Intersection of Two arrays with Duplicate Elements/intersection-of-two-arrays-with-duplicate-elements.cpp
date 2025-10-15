class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        
        while(i < a.size() && j < b.size()){
            
            if(i > 0 && a[i] == a[i-1]){
                i++;
                continue;
            }
            
            if( j > 0 && b[j] == b[j-1]){
                j++;
                continue;
            }
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
                
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};