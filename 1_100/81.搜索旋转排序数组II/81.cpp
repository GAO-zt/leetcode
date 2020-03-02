class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        
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
            return false;
        }
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target) {            
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return (nums[lo] == target);
    }

private:
    int search_min_pos(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[hi]) {
                // 旋转点一定在(mid, hi]
                lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                // 旋转点一定在(lo, mid]
                hi = mid;
            } else {
                // 不确定旋转点, 由于重复项与33题不一样需要做修改
                // 在[mid, hi]区间内，判断是否一直相等，来确定旋转点在哪边
                int i = mid + 1;
                while (i < hi) {
                    if (nums[i] > nums[mid]) {
                        // 中间出现一个更大值, 说明旋转点在(i, hi]                    
                        lo = i + 1;
                        break;
                    } else if (nums[i] < nums[mid]) {
                        // 中间出现一个更小值, 不满足单调性，说明旋转点是 i 本身 
                        return i;
                    }
                    // 相同就继续往下判断
                    ++i;
                }
                // 说明这个区间内全部相等，有单增特性说明旋转点在(0, mid]
                hi = mid;
            }
        }
        return lo;
    }
};