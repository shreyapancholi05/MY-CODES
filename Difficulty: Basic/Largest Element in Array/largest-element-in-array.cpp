class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = arr[0];
        
        for(auto i : arr){
            if(i > max){
                max = i;
            }
        }
        return max;
    }
};
