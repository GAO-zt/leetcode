class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return {-1};
        
        vector<int> res;
        // 存储排序前各区间左边界与索引
        vector<pair<int, int>> lefts;
        for (int i = 0; i < intervals.size(); ++i) {
            lefts.push_back({intervals[i][0], i});
        }
        
        std::sort(lefts.begin(), lefts.end(), [](pair<int,int> p1, pair<int,int> p2) {return p1.first < p2.first;});

        for (int i = 0; i < intervals.size(); ++i) {
            int lo = 0;
            int hi = intervals.size();
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (lefts[mid].first < intervals[i][1]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            res.push_back((lo == intervals.size()) ? -1 : lefts[lo].second);
        }
        return res;
    }
};

// stl
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return {-1};
        
        vector<int> res;
        // 存储排序前各区间左边界与索引
        vector<pair<int, int>> lefts;
        for (int i = 0; i < intervals.size(); ++i) {
            lefts.push_back({intervals[i][0], i});
        }
        
        std::sort(lefts.begin(), lefts.end(), [](pair<int,int> p1, pair<int,int> p2) {return p1.first < p2.first;});

        for (int i = 0; i < intervals.size(); ++i) {
            // 不关心second是什么值，随意make pair就可以了
            auto it = std::lower_bound(lefts.begin(), lefts.end(), std::make_pair(intervals[i][1], 0));
            res.push_back((it == lefts.end()) ? -1 : (*it).second);
        }
        return res;
    }
};