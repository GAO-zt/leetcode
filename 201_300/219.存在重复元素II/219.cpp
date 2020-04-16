
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) return false;

        // 元素及其上一个位置
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if ((m.find(val) != m.end()) && (i - m[val] <= k)) {
                return true;
            } else {
                m[val] = i;
            }
        }
        return false;
    }
};