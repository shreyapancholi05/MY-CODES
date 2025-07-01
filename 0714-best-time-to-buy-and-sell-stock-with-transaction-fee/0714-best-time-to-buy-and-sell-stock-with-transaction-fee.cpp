class Solution {
    int profit(vector<int>& prices, int day, int state, vector<vector<int>> & table, int fee){
        int n = prices.size();
        if(day >= n)
            return 0;
        if(table[state][day] != -1)
            return table[state][day];
        int maxPro = 0;
        if(state == 0){
            int buy = -prices[day] + profit(prices, day + 1, 1, table, fee);
            int dontbuy = profit(prices, day+1 , 0, table, fee);
            maxPro = max(buy, dontbuy);
        }
        else{
            int sell = prices[day] - fee + profit(prices , day+1, 0, table, fee);
            int dontsell = profit(prices, day+1 , 1, table, fee);
            maxPro = max(sell , dontsell);
        }
        return table[state][day] = maxPro;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<vector<int>> table(2, vector<int>(n, -1));
        return profit(prices, 0 , 0, table, fee);
    }
    
};