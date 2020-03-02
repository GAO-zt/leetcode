class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int cnt = 0;
        int n = nums.size();

        int lo = 0;
        int hi = n - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                lo = mid;
                break;
            }
        }
        
        if (nums[lo] == target) {
            int i = lo;
            while(i < n && nums[i] == target) {
                ++cnt;
                ++i;
            } 

            int j = lo - 1;
            while(j >= 0 && nums[j] == target) {
                ++cnt;
                --j;
            }
        }
        return cnt;
    }
};