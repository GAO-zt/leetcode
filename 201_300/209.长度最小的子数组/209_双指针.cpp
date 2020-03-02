class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int min = INT_MAX; // 因为要做比较
        int left = 0;
        int right = 0;
        int curr_sum = nums[0];
        while (left < nums.size() && right < nums.size() && left <= right) {        
            // 滑窗，左移减，右移加
            if (curr_sum >= s) {
                min = std::min(right - left + 1, min);
                curr_sum -= nums[left++];
            } else {
                ++right;
                if(right != nums.size()) curr_sum += nums[right];
            }
        }
        return (min == INT_MAX) ? 0 : min;
    }
};