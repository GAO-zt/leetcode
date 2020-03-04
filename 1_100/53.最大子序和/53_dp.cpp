class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 以nums[i]结尾的子序列最大和
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }
        return *(std::max_element(dp.begin(), dp.end()));
    }
};

// 改进写法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 以nums[i]结尾的子序列最大和
        int max_sub_sum = nums[0];
        int max_prev_sub_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            printf("max_prev_sub_sum = %d\n", max_prev_sub_sum);
            if (max_prev_sub_sum > 0) {
                max_prev_sub_sum = max_prev_sub_sum + nums[i];
            } else {
                max_prev_sub_sum = nums[i];
            }
            max_sub_sum = std::max(max_sub_sum, max_prev_sub_sum);
        }
        return max_sub_sum;
    }
};