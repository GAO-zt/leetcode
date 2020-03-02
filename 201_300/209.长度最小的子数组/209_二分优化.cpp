class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;

        int lo = 1;
        int hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi -lo) / 2;
            vector<int> subArrayFlags = collectSubArraySumGreaterThanTarget(s, mid, nums);
            if (std::find(subArrayFlags.begin(), subArrayFlags.end(), 1) != subArrayFlags.end()) {
                // 在长度为 mid 的sum组合中找到了大于等于s的, 下一步找更短的组合
                hi = mid;                
            } else {
                // 没找到，下一步找更长的组合
                lo = mid + 1;
            }
        }  
        return (lo == nums.size() && accumulate(nums.begin(), nums.end(), 0) < s)? 0 : lo;      
    }

private:
    vector<int> collectSubArraySumGreaterThanTarget(int target, int len, vector<int>& nums) {
        vector<int> flags;
        // 相比每个子序列都用累加，保留了交叠部分和，以减少计算时耗
        int prev_sum = std::accumulate(nums.begin(), nums.begin()+len, 0);
        flags.push_back(prev_sum >= target);
        for (int i = 1; i <= nums.size() - len; ++i) {
            // 相当于做了一个右移的滑窗，去掉左边加上右边
            int curr_sum = prev_sum - nums[i - 1] + nums[i + len - 1];
            flags.push_back(curr_sum >= target);
            prev_sum = curr_sum;
        }
        return flags;
    }
};