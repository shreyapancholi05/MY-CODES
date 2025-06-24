#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
class Solution {
  public:
  

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
         
        oset os;
        int ans  = 0;
        for(int i : arr){
            ans += os.order_of_key(i);
            os.insert(i);
        }
        
        return ans;
        
        
    }
};