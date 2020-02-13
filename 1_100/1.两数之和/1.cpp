class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> new_map;
        for(int i=0;i<nums.size();i++) {
            int comp = target - nums[i];
            if (new_map.find(comp) != new_map.end()) {
                // 注意调换下标顺序，因为map里的是更早的值
                return {new_map[comp], i};
            }
            new_map.insert({nums[i], i});
        }
        return {};
    }
};