class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int p = 0;

        for(int r = 1; r < prices.size(); ++r){
            
            // If making a profit
            if(prices[r] > prices[l]){

                // if profit made is bigger than whatever profit we're earning currently
                if(prices[r] - prices[l] > p) {
                    p = prices[r] - prices[l];
                }
            } else {
                l = r;
            }
        }

        return p;
    }
};
