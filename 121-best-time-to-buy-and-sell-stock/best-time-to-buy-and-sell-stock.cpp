class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxPrice = 0;

        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxPrice = max(maxPrice, profit);
            }else {
                l = r; // updating the minimum price
            } 
            r++;
        }
        return maxPrice;
    }
};