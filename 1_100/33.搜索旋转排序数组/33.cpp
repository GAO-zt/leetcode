class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        // 先找出旋转点坐标（最小值）
        int min_pos = search_min_pos(nums);
        int max_pos = (min_pos == 0) ? (nums.size() - 1) : (min_pos - 1);
        int min_val = nums[min_pos];
        int max_val = nums[max_pos];

        int lo, hi;
        // 确定在哪个区间进行二分
        if (target >= nums[0] && target <= max_val) {
            lo = 0;
            hi = max_pos;
        } else if (target >= min_val && target <= nums[nums.size() - 1]) {
            lo = min_pos;
            hi = nums.size() - 1;
        } else {
            return -1;
        }
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target) {            
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return (nums[lo] == target) ? lo : -1;
    }

private:
    int search_min_pos(vector<int>& nums) {
        // 2020.0227 如果有重复项的话有缺陷，见题81
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[hi]) {
                // 旋转点一定在右边
                lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                // 旋转点一定在左边
                hi = mid;
            } else {
                // 不确定旋转点
                hi = hi - 1;
            }
        }
        return lo;
    }
};