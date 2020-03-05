class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int max_profit = 0; // 迄今为止的最大利润
        int min_price = INT_MAX; // 迄今为止的历史低价
        for (int i = 0; i < prices.size(); ++i) {
            min_price = std::min(min_price, prices[i]); // 更新历史低价
            max_profit = std::max(max_profit, prices[i] - min_price); // 更新最大利润
        }
        return max_profit;
    }
};