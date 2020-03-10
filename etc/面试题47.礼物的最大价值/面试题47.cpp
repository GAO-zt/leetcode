
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        if (row == 1) return std::accumulate(grid[0].begin(), grid[0].end(), 0);
        if (col == 1) {
            int sum = 0;
            for(auto i : grid) {
                sum += i[0];
            }
            return sum;
        }

        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < col; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};


// 一维数组
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        if (row == 1) return std::accumulate(grid[0].begin(), grid[0].end(), 0);
        if (col == 1) {
            int sum = 0;
            for(auto i : grid) {
                sum += i[0];
            }
            return sum;
        }
        // 到达当前行的这个方格的最大值
        vector<int> dp(col);
        dp[0] = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j == 0) {
                    dp[0] += grid[i][0];
                } else {
                    dp[j] = std::max(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }

        return dp[col - 1];
    }
};