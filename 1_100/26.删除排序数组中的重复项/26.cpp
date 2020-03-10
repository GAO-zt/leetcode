class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int curr_num = nums[0];
        int j = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != curr_num) {
                curr_num = nums[i];
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};