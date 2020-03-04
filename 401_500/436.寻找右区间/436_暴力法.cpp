class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return {-1};
        
        vector<int> res;
        for (auto i : intervals) {
            int curr_right = i[1];
            int idx = -1;
            int next_min_left = INT_MAX;
            for (int j = 0; j < intervals.size(); ++j) {
                int next_left = intervals[j][0];
                if (next_left >= curr_right && next_left < next_min_left) {
                    // 只有当前左值大于目标右值且这个左值更小，才会更新
                    next_min_left = next_left;
                    idx = j;
                }
            }
            res.push_back(idx);
        }
        return res;
    }
};