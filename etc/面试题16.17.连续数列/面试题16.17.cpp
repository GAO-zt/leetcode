
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
        }
        return *(std::max_element(dp.begin(), dp.end()));
    }
};