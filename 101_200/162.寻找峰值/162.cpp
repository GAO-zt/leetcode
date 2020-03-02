class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) {
                // 处在一个上升区间中，峰值必然在[mid, hi)
                lo = mid + 1;
            } else {
                // 题设有nums[i] ≠ nums[i+1]
                // 处在下降区间，峰值必然在[lo, mid)
                hi = mid;
            }
        }
        return lo;
    }
};