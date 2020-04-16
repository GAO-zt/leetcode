class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int max_cnt = 0;
        int prev_num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                ++cnt;
                prev_num = 1;
            } else {
                if (prev_num == 1) max_cnt = std::max(max_cnt, cnt);
                cnt = 0;
            }     
        }
        return std::max(max_cnt, cnt);
    }
};