class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        while(lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            // 注意取严格大于值，所以相等的情况也要向更大的方向去找
            if(letters[mid] <= target) {
                lo = mid + 1;                
            } else {
                hi = mid;
            }
        }
        if (letters[lo] > target) {
            return letters[lo];
        } else {
            // 如果与target相等的情况下说明必然一直找到了结尾还没有找到更大值;
            return letters[0];
        }        
    }
};