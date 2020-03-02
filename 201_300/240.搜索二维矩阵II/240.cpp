class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n - 1;
        for (int r = 0; r < m; ++r) {
            left = 0;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (matrix[r][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            if (matrix[r][left] == target) {
                return true;
            } else if (matrix[r][left] > target) {
                --right;
            }
        }
        return false;
    }
};