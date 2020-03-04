// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.empty()) return 0;
        
//         int max_len = 1;
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             int base_val = nums[i];
//             int curr_max_val = base_val;
//             int curr_len = 1;

//             int j = i + 1;
//             while (j < nums.size()) {
//                 if (nums[j] > curr_max_val) {
//                     curr_max_val = nums[j];
//                     ++curr_len;
//                 } else {   
//                     curr_max_val = (nums[j] > base_val) ? nums[j] : base_val;
//                     curr_len = (nums[j] > base_val) ? 
//                     // --curr_len;


//                 }
//                 printf("base_val = %d, curr_max_val = %d, nums[%d] = %d, curr_len = %d\n", base_val, curr_max_val, j, nums[j], curr_len);
//                 ++j;
//                 if (max_len < curr_len) {
//                     max_len = curr_len;
//                 }                          
//             }
//         }
//         return max_len;
//     }
// };


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.empty()) return 0;
        
//         int max_len = 1;
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 int base_val = nums[i];                
//                 int curr_max_val = base_val;                
//                 int curr_len = 1;
//                 for (int k = j; k < nums.size(); ++k) {
//                     if (nums[k] > curr_max_val) {
//                         curr_max_val = nums[k];
//                         ++curr_len;
//                         printf("base_val = %d, curr_max_val = %d, nums[%d] = %d, curr_len = %d\n", base_val, curr_max_val, k, nums[k], curr_len);                       
//                     } else {
//                         printf("base_val = %d, curr_max_val = %d, nums[%d] = %d, curr_len = %d\n", base_val, curr_max_val, k, nums[k], curr_len);                          
//                         break;
//                     }
//                 }
//                 if (max_len < curr_len) {
//                     max_len = curr_len;
//                 }          
//             }
//         }
//         return max_len;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_len = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int base_val = nums[i];                
                int curr_max_val = base_val;                
                int curr_len = 1;
                for (int k = j; k < nums.size(); ++k) {
                    if (nums[k] > curr_max_val) {
                        curr_max_val = nums[k];
                        ++curr_len;
                    }
                    if (base_val == 2)
                        printf("base_val = %d, curr_max_val = %d, nums[%d] = %d, curr_len = %d\n", base_val, curr_max_val, k, nums[k], curr_len);
                }
                if (max_len < curr_len) {
                    max_len = curr_len;
                }          
            }
        }
        return max_len;
    }
};