class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int> uni;

        int n = a.size();
        int m = b.size();

        for(int i = 0; i<n; i++){
            uni.insert(a[i]);
        }

        for(int j = 0; j<m; j++){
            uni.insert(b[j]);
        }

        vector<int> result(uni.begin(), uni.end());
        return result;

    }
};