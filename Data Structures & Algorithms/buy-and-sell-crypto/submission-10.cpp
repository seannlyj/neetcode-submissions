class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int profit = 0;

        while(r < prices.size()) {

            // if left price is smaller than right price (aka there is a profit)
            if(prices[l] < prices[r]) {
                int currentProfit = prices[r] - prices[l];
                profit = max(profit, currentProfit);
            } else {
                l = r;
            }

            r++;
        }

        return profit;
    }
};
