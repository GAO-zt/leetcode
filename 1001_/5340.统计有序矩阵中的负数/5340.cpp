class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int neg_cnt = 0;
        int start_col = 0;
        for(int row = m - 1; row >= 0; --row) {
            // 因为非递增排列，同一列上面行对应的数字一定不小于当前数，倒序遍历矩阵每一行, 在行内做二分查找
            int lo = start_col;
            int hi = n; // 注意没有 -1
            while(lo < hi) {
                int mid = (hi - lo) / 2 + lo;
                // 向小于0的位置查找
                if(grid[row][mid] >= 0) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            if (lo == n) {
                // 找到了尾后，说明这一行没有找到负数，那么上面所有行都没有负数
                break;
            }
            if (grid[row][lo] >= 0) {
                // 返回了一个正数
                neg_cnt = neg_cnt + (n - lo) - 1;
            } else {
                neg_cnt = neg_cnt + (n - lo);
            }
            // 上一行直接从已有负数位置去找，跳过前面位置（一定无负数）
            start_col = lo;
        }
        return neg_cnt;
    }
};