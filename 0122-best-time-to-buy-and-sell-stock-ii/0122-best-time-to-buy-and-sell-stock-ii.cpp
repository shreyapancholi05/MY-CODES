class Solution {
    int profit(vector<int>& prices, int day, int state, vector<vector<int>>& table){
        int n = prices.size();
        if(day == n)
            return 0;
        if(table[state][day] != -1)
            return table[state][day];
        int maxPro = 0;
        if(state == 0){
            int buy = -prices[day] + profit(prices, day+1 , 1, table);
            int dontbuy = profit(prices, day+1 , 0, table);
            maxPro = max(buy, dontbuy); 
        }
        else{
            int sell = prices[day] + profit(prices , day+1 , 0,table);
            int dontsell =  profit(prices, day+1 , 1, table);
            maxPro = max(sell , dontsell);
        }
        return table[state][day] = maxPro;

    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> table(2, vector<int>(n, -1));
        
        return profit(prices, 0 , 0, table);
    }
};
/*int n = prices.size();
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(prices[i+1] > prices[i]){
                int profit = prices[i+1] - prices[i];
                ans = ans + profit;
            }
        }
        return ans;
        */