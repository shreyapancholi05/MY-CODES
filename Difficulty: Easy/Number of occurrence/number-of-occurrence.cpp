class Solution {
  public:
    int first(vector<int>& arr, int target){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        
        int ans1 = -1;
        while(start<=end){
            if(arr[mid] == target){
                ans1 = mid;
                end = mid - 1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
         mid = start + (end - start)/2;   
        }
        return ans1;
    }
    
    int last(vector<int>& arr, int target){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        
        int ans2 = -1;
        while(start<=end){
            if(arr[mid] == target){
                ans2 = mid;
                start = mid+1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
            mid = start + (end - start)/2;
        }
        return ans2;
    }
    
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int a = first(arr, target);
        int b = last(arr, target);
        
        if(a == -1 || b == -1) return 0;
        return b-a+1;
        
    }
};
