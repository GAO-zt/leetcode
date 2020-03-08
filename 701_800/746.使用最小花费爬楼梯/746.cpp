class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.empty()) return 0;
        
        // 从第i个阶梯出发时，已经产生的最小花费
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            // 从前两级阶梯中找到花费最小的
            dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }
        // 注意只判断最后两项，因为登顶前只到达倒数1与倒数2阶
        return std::min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};