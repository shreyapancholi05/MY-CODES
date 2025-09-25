class Solution {
public:
int solve1(vector<int> &cost, int n){
    //base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }
    int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));
    return ans;
}

    int solve(vector<int> &cost, int n, vector<int> &dp){
        if(n == 1) return cost[1];
        if(n == 0) return cost[0];

        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int ans = min(solve1(cost, n-1),solve1(cost, n-2));
        // return ans;

        vector<int> dp(n+1, -1);
         int ans = min(solve(cost, n-1, dp),solve(cost, n-2, dp));
        return ans;

    }
};