class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = (hi - lo) / 2 + lo; 
        while(hi != lo) {
            if(target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
            mid = (hi - lo) / 2 + lo;
        }
        if (target > nums[mid]) {
            return mid + 1;
        } else {
            return mid;
        }
    }
};