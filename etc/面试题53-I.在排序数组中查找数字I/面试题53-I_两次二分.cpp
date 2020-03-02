class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int lower = search_lower(nums, target);
        if (lower == -1) 
            return 0;
        
        int upper = search_upper(nums, target);
        return upper - lower + 1;
    }

private:
    int search_lower(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int lo = 0;
        int hi = nums.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                // 所有相等情况，区间一律向左
                hi = mid;
            }
        }
        if (lo == nums.size() || nums[lo] != target) {
            return -1;
        } else {
            return lo;
        }
    }    

    int search_upper(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int lo = 0;
        int hi = nums.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                // 所有相等情况，区间一律向右
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (lo == 0 || nums[lo - 1] != target) {
            return -1;
        } else {
            return lo - 1;
        }
    }    

};
