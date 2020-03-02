class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == mid) {
                // 相当于找到值等于下标的右边界，此题特殊，所以用 == 就可以了
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};