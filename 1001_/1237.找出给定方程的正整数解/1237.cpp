/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> solution;

        int y_end = 1000;
        // 由于题设函数单调性，如果从x开始遍历，则y的范围是可以筛选的
        // 例如假如 z == f(5,4), 显然
        // f(4,4) < f(5,4) < f(6,4)
        // f(5,3) < f(5,4) < f(5,5)
        // 那么也可以得到：
        // f(5,3) < f(5,4) = z < f(6,4) < f(6,5)
        // 也就是说在x_next的迭代中，y_next的上界必然不大于当前y（否则必然大于z）
        for (int x = 1; x <= 1000; x++) {
            // 在y轴方向二分查找
            int y_lo = 1;
            int y_hi = y_end;
            int y_mid = y_lo + (y_hi - y_lo) / 2;
            while(y_hi > y_lo) {
                int res = customfunction.f(x,y_mid);
                if (z == res) {
                    solution.push_back({x,y_mid});
                    y_end = y_mid;  // 所以每次迭代缩小y的上界
                    break;
                } else if (z > res) {
                    y_lo = y_mid + 1;
                } else {
                    y_hi = y_mid;
                }
                y_mid = y_lo + (y_hi - y_lo) / 2;
            }

            // 当y的上界已经等于1时，则之后必然大于z，停止迭代
            if (1 == y_end) {
                break;
            }
        }
        
        //printf("exec_cnt = %d\n", exec_cnt);
        return solution;
    }
};