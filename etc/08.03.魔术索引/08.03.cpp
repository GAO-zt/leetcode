// 二分尝试失败，因为该索引前后值的大小顺序不确定，
// class Solution {
// public:
//     int findMagicIndex(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> nums_;
//         for (int i = 0; i < n; ++i) {
//             nums_.push_back(nums[i] - i);
//         }
//         int lo = 0;
//         int hi = n;
//         while (lo < hi) {
//             int mid = (hi - lo) / 2 + lo;
//             printf("%d, %d, %d\n", lo, hi, mid);
//             if(nums_[mid] < 0) {
//                 lo = mid + 1;
//             } else {
//                 hi = mid;
//             }
//         }
//         if (lo == n) {
//             return -1;
//         } 
//         if (nums_[lo] == 0) {
//             return lo;
//         } else {
//             return -1;
//         }
//     }
// };


class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == i) {
                return i;
            }
        }
        return -1;
    }
};