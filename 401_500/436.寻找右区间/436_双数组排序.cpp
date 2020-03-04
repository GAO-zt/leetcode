// 官方解法5，速度有点慢
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return {-1};
        
        vector<int> res(intervals.size());
        // 存储排序前各区间左边界与索引
        map<vector<int>, int> m;
        for (int i = 0; i < intervals.size(); ++i) {
            m[intervals[i]] = i;
        }

        vector<vector<int>> starts = intervals;
        vector<vector<int>> ends = intervals;

        std::sort(starts.begin(), starts.end(), [](vector<int> v1, vector<int> v2) {return v1[0] < v2[0];});
        std::sort(ends.begin(), ends.end(), [](vector<int> v1, vector<int> v2) {return v1[1] < v2[1];});

        int i = 0;
        int j = 0;
        while(i < intervals.size()) {
            while(j < intervals.size()) {
                if (starts[j][0] >= ends[i][1]) {
                    res[m[ends[i]]] = m[starts[j]];
                    break;
                } else {
                    j++;
                }
            }
            if (j == intervals.size()) {
                res[m[ends[i]]] = -1;
            }

            i++;
        }
        return res;
    }
};