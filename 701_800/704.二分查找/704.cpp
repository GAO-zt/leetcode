class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = (hi - lo) / 2 + lo;
        while(lo < hi) {
            if(nums[mid] < target) {
                lo = mid + 1;       
            }
            else {
                hi = mid;
            }
            mid = (hi - lo) / 2 + lo;
        }
        return (target == nums[mid]) ? mid : -1;
    }
};