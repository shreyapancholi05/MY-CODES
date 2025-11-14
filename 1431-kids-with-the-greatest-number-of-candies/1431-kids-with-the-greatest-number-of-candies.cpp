class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = *max_element(candies.begin(), candies.end());

        int n = candies.size();
        vector<bool> result(n);

        for(int i=0; i<n; i++){
            if(candies[i] + extraCandies >= maximum){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }

        return result;
    }
};