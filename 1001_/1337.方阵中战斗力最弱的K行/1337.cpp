class Solution {
public:
    static bool cmpVal(const pair<int, int>& a, const pair<int, int>& b) {
        // 对应题设条件
        return (a.second < b.second) || ((a.second == b.second) && (a.first < b.first));
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int, int>> record;
        vector<int> res;
        
        for(int row = 0; row < m; row++) {
            int score = 0;
            for(int col = 0; col < n; col++) {
                if(mat[row][col] > 0) {
                    score++;
                }         
            }
            record.push_back({row, score});
        }

        sort(record.begin(), record.end(), cmpVal);
        // sort(record.begin(), record.end(), 
        //     [](const auto& a, const auto& b){return a.second < b.second;});

        for(int i = 0; i < k; i++) {
            res.push_back(record[i].first);
        }

        return res;
    }
};