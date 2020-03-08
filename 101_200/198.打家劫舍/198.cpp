class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size()); // 前进到当前房屋时的最大收益
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            // 如果 (i-1) 的收益已经比 (i-2) + (i) 的价值要大
            // 那就选择偷 (i-1) 所能得到的最大值，而不偷 (i-2) + (i)
            // 反之亦然        
            if (dp[i - 1] >= dp[i - 2] + nums[i]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 2] + nums[i];
            }
        }
        return *(std::max_element(dp.begin(), dp.end()));

    }
};

// 改进写法
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size()); // 前进到当前房屋时的最大收益
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            // 如果 (i-1) 的收益已经比 (i-2) + (i) 的价值要大
            // 那就选择偷 (i-1) 所能得到的最大值，而不偷 (i-2) + (i)
            // 反之亦然        
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return *(std::max_element(dp.begin(), dp.end()));

    }
};