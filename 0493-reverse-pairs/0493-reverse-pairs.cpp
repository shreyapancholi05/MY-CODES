#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  typedef tree<long, null_type, greater_equal<long>, rb_tree_tag, tree_order_statistics_node_update> oset;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        oset os;
        int ans = 0;
        for(int i : nums){
            ans += os.order_of_key(2L*i);
            os.insert(i);
        }
        return ans;
    }
};