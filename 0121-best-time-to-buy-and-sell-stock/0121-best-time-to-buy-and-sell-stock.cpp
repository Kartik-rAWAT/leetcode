class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prices = prices[0];
        int best = 0;
        for (int p : prices) {
            if (p < min_prices) {
                min_prices = p;
            } else {
                best = max(best, p - min_prices);
            }
        }
        return best;
    }
};