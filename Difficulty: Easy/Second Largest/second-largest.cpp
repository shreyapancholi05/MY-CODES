class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = arr[0];
        int second = -1;
        
        for(int i=1; i<n; i++){
            if(arr[i] > maxi){
                second = maxi;
                maxi = arr[i];
            }
            else if(arr[i] < maxi && arr[i] > second){
                second = arr[i];
            }
        }
        return second;
    }
};