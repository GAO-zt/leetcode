class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 双指针法
        vector<int> num_inter;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
       
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j <nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                num_inter.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return num_inter;
    }
};