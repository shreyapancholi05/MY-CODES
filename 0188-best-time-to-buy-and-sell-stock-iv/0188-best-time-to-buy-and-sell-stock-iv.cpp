class Solution {
     int profit(vector<int>& prices, int day, int state, int k, vector<vector<vector<int>>> &table){
        int n = prices.size();
        if(day >= n || k == 0)
            return 0;
        if(table[day][state][k] != -1)
            return table[day][state][k];
        
        int maxPro = 0;
        if(state == 0){
            int buy = -prices[day] + profit(prices, day+1 , 1,k , table);
            int dontbuy = profit(prices, day+1 , 0, k, table);
            maxPro = max(buy, dontbuy); 
        }
        else{
            int sell = prices[day] + profit(prices , day+1 , 0,k-1, table);
            int dontsell =  profit(prices, day+1 , 1,k , table);
            maxPro = max(sell , dontsell);
        }
        return table[day][state][k] = maxPro;

    }
public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        vector<vector<vector<int>>> table(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        
        return profit(prices, 0 , 0, k, table);
    
    }
};