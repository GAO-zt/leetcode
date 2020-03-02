class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (numbers[mid] > numbers[hi]) {
                // 旋转点一定在右边
                lo = mid + 1;      
            } else if (numbers[mid] < numbers[hi]) {
                // 旋转点一定在左边
                hi = mid;
            } else {
                // 不确定，需要缩减范围进一步判断
                hi = hi - 1;
            }
        }
        return numbers[lo];
    }
};

// 参考了 https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
// 重点是要利用分段升序的特性