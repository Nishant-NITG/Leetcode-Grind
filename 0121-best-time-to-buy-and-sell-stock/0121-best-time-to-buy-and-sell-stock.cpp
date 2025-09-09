class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Start with a huge value
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Update minimum price so far
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            // Calculate profit if sold today
            int profit = prices[i] - minPrice;

            // Update maxProfit if current profit is higher
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
