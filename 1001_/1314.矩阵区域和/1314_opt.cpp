
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if (mat.empty() || mat[0].empty()) return {{0}};

        int row = mat.size();
        int col = mat[0].size();

        // 两边padding 0
        vector<vector<int>> mat_pad(row, vector<int>(col + 2 * K, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat_pad[i][K + j] = mat[i][j];
            }
        }

        vector<vector<int>> row_psum(row + 2 * K, vector<int>(col));  
        for (int i = 0; i < K; ++i) {
            row_psum[i] = vector<int>(col, 0);
            row_psum[i + row + K] = vector<int>(col, 0);
        }

        // 求每一个子区域在行方向的部分和
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j == 0) {
                    row_psum[i + K][j] = std::accumulate(mat_pad[i].begin(), mat_pad[i].begin() + 2 * K + 1, 0);
                } else {
                    row_psum[i + K][j] = row_psum[i + K][j - 1] - mat_pad[i][j - 1] + mat_pad[i][j + 2 * K];
                }
            }
        }   

        // 按列累加行方向的部分和至总和，注意求第一行的特殊情况
        vector<vector<int>> sum(row, vector<int>(col));  
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                if (i == 0) {
                    for (int kk = 0; kk < 2 * K + 1; ++kk) {
                        if (kk == 0) {
                            sum[0][j] = 0;
                        } else {
                            sum[0][j] += row_psum[kk][j];
                        }
                    }            
                } else {
                    sum[i][j] = sum[i - 1][j] - row_psum[i - 1][j] + row_psum[i + 2 * K][j];
                }        
            }
        }

        return sum;
    }
};