class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        //  前 i 个数字的最长子序列长度， 初始值为1表示任何数至少自成长度1
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            // 到头开始判断到当前值的子序列长度
            for (int j = 0; j < i; ++j) {
                // nums[i] 可以作为一个新的上升子序列的最大值（任意一个）
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }    
            }
        }
        for (auto j : dp) {
            printf("%d, ", j);
        }
        printf("\n");
        return *std::max_element(dp.begin(), dp.end());
    }
};