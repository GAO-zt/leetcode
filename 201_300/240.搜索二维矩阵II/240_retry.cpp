class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int down = 0;           
        int up = m - 1;
        int left = 0;
        int right = n - 1;

        int row = 0;
        int col = 0;
        // 分别从行列两个方向去缩小查找范围
        while (row <= up && col <= right) {   
            left = col;
            while (left < right) {
                int col_mid = left + (right - left) / 2;
                if (matrix[row][col_mid] < target) {
                    left = col_mid + 1;
                } else {
                    right = col_mid;
                }
            }
            if (matrix[row][left] == target) {
                return true;
            } else if (matrix[row][left] > target) {
                --right;
            }
     
            down = row;
            while (down < up) {
                int row_mid = down + (up - down) / 2;
                if (matrix[row_mid][col] < target) {
                    down = row_mid + 1;
                } else {
                    up = row_mid;
                }
            }
            if (matrix[down][col] == target) {
                return true;
            } else if (matrix[down][col] > target) {
                --up;
            }         

            ++row;
            ++col;
        }
        
        return row != m && col != n && (matrix[row][col] == target);
    }
};