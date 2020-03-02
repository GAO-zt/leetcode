// 结果是对的，但时耗过大

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
        if (lo == nums.size() && accumulate(nums.begin(), nums.end(), 0) < s) {            
            // 跳出循环时仍未找到
            return 0;
        } else {
            return lo;
        }
    }

private:
    vector<int> collectSubArraySumGreaterThanTarget(int target, int len, vector<int>& nums) {
        vector<int> flags;
        for (int i = 0; i <= nums.size() - len; ++i) {
            flags.push_back(accumulate(nums.begin()+i, nums.begin()+i+len, 0) >= target);
        }
        
        // for (auto i : flags) printf("%d ", i);
        // printf("\n");
        
        return flags;
    }
};