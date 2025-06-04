class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i-1] <= arr[i]){
                
            }
            else{
                return false;
            }
        }
        return true;
    }
};