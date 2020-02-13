class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> num1_set;
        vector<int> num_inter;
        for(auto it = nums1.begin();it != nums1.end(); ++it) {
            num1_set.insert(*it);
        }
        for(auto it = nums2.begin();it != nums2.end(); ++it) {
            if(num1_set.find(*it) != num1_set.end()) {
                num_inter.push_back(*it);
                num1_set.erase(*it);
                if(num1_set.empty()) {
                    return num_inter;
                }
            }
        }
        return num_inter;
    }
};