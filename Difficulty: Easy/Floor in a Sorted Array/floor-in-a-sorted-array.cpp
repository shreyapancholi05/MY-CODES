class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        
        int ans = -1;
        
        while(s<=e){
            if(arr[mid] <= x){
                ans = mid;
                s = mid + 1;
                
            }
            else{
                e = mid -1;
            }
            
            mid = s+(e-s)/2;
            
        }
        return ans;
    }
};
