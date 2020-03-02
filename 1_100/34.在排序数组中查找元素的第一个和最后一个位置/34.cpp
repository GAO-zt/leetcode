class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int lower_bound = -1;
        int upper_bound = -1;

        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if(lo != nums.size() && nums[lo] == target) {
            lower_bound = lo;
        } else {
            return {-1, -1};
        }

        lo = 0;
        hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        upper_bound = lo - 1;

        return {lower_bound, upper_bound};

    }
};