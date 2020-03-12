
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         if (nums.empty()) return false;

//         // 元素及其上一个位置
//         vector<int, int> v;
//         for (int i = 0; i < nums.size(); ++i) {
//             v.push_back({nums[i], i});
//         }
        
//         sort(v.begin(), v.end(), [](const std::pair<int,int> &a, const std::pair<int,int> &b) {return a.first < b.first;})

//         for (int i = 1; i < v.size(); ++i) {
//             if (v[i].first == v[i - 1].first && v[i].second == v[i - 1].second();
//         }
//         return false;
//     }
// };