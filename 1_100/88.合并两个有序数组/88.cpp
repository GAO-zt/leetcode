class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> merges(m + n);
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merges[k++] = nums1[i];
                ++i;
            } else {
                merges[k++] = nums2[j];
                ++j;
            }
        }
        printf("i = %d, j = %d, k = %d\n", i, j, k);
        if (i == m) {
            while (j < n) {
                merges[k++] = nums2[j++];
            }
        }
        printf("i = %d, j = %d, k = %d\n", i, j, k);
 
        if (j == n) {
            while (i < m) {
                merges[k++] = nums1[i++];
            }
        }
        printf("i = %d, j = %d, k = %d\n", i, j, k);

        nums1 = merges;
    }
};