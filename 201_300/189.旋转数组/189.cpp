// 借助一个额外空间, STL
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        vector<int> temp(nums.end() - k, nums.end()); // k
        std::copy(nums.begin(), nums.end() - k, nums.begin() + k); // n - k    
        std::copy(temp.begin(), temp.end(), nums.begin()); // k
    }
};