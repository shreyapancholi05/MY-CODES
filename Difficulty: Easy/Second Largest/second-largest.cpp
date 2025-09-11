class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int secondlar = -1;
        int max = arr[0];
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > max){
                secondlar = max;
                max = arr[i];
            }
            
            else if(arr[i] < max && arr[i] > secondlar){
                secondlar = arr[i];
            }
            
            
        }
        return secondlar;
    }
};