class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
            if (m[i] > 1) {
                return true;
            }
        }
        return false;
    }
};