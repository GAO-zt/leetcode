
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
        // 用抽屉原理判断大于中位值的数量，然后作二分
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            // 从题设条件里，给出一个当前区间大小对应的中位数值
            int mid = lo + (hi - lo) / 2;
            // 判断整个区间内小于等于该中位值的数字数量
            int cnt = 0;
            for (int i : nums) {
                if (i <= mid) cnt++; 
            }

            if (cnt > mid) {
                // 数量严格大于中位数，表示[0,mid)内的数字数量比它的范围要大，即存在重复数
                hi = mid;
            } else {
                // 表示[0,mid)范围内的数字小于等于范围，重复数在另一个区间
                lo = mid + 1;
            }
        }    
        return lo;
    }
};