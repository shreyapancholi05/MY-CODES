class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = -1;
        for(auto it : arr){
            if(it > max){
                max = it;
            }
        }
        return max;
    }
};
