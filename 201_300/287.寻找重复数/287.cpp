class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> num_set;
        for (auto i : nums) {
            if (num_set.find(i) != num_set.end()) {
                return i;
            } else {
                num_set.insert(i);
            }
        }   
        return 0;
    }
};