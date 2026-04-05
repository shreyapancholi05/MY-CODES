class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largest = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        
        return largest;
    }
};
