class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            printf("%d, %d\n", nums[i], nums[i - i]);
            if (nums[i] == nums[i - i]) {
                return true;
            }
        }
        return false;
    }
};