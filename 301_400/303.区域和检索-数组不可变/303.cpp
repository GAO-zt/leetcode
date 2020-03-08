class NumArray {
public:
    vector<int> sub_sums;
    
    NumArray(vector<int>& nums) {
        // 缓存一个子项表
        sub_sums.resize(nums.size() + 1);
        sub_sums[0] = 0; // 避免sumRange里对 i == j 的判断
        for (int i = 0; i < nums.size(); ++i) {
            sub_sums[i + 1] = sub_sums[i] + nums[i]; 
        }
    }
    
    int sumRange(int i, int j) {
        return sub_sums[j + 1] - sub_sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */