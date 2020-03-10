
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if (mat.empty() || mat[0].empty()) return {{0}};

        row = mat.size();
        col = mat[0].size();

        padding_row = row + K * 2;
        padding_col = col + K * 2;

        vector<vector<int>> mat_pad(padding_row, vector<int>(padding_col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < row; ++j) {
                mat_pad[K + i][K + j] = mat[i][j];
            }
        }
        vector<vector<int>> res(row, vector<int>(col));  
        res[0][0] = 0;

        for (int i = 0; i < row; ++i) {
            if ()          
        
        
    
};