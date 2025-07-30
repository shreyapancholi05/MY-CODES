class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int secondlargest = -1;
        int maxelem = arr[0];
        
        for(int i = 1; i<arr.size(); i++){
            if(arr[i] > maxelem){
                secondlargest = maxelem;
                maxelem = arr[i];
                
            
            }
            else if(arr[i] < maxelem && arr[i] > secondlargest){
                secondlargest = max(arr[i], secondlargest);
            }
        }
        return secondlargest;
    }
};