class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for(int price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
};