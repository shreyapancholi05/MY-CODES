class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = -1; 
        int secondlar = -1;
        
        for(int i = 0; i<n; i++){
            if(arr[i] > largest){
                secondlar = largest;
                largest = arr[i];
                
            }
            else if(arr[i] < largest && arr[i] > secondlar){
                secondlar = arr[i];
            }
        }
        
        return secondlar;
    }
};