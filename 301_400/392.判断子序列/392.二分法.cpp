class Solution {
public:
    bool isSubsequence(string s, string t) {
        // map后的二分查找, 改良vector一下
        vector<vector<int>> m(26); //存储字符及其对应下标，必定是以升序排列(a ~ z)
        for (int i = 0; i < t.size(); i++) {
            m[(int)(t[i] - 'a')].push_back(i); 
        }
        
        int t_idx = -1; // 表示下一次查找时在t中的位置
        for (int i = 0; i < s.size(); i++) {                 
            // 二分查找是二分的idx
            int char_idx = (int)(s[i] - 'a');
            int lo = 0;
            int hi = m[char_idx].size() - 1;
            while (lo < hi) {
                int mid = (hi + lo) / 2;
                if(m[char_idx][mid] > t_idx) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            // t中没有对应的字母 or 匹配到该字符的位置已经落后于当前t
            if (hi == -1 || m[char_idx][lo] <= t_idx) {
                return false;
            }
            t_idx = m[char_idx][lo]; // 推进下一次的查找
        }

        return true;
    }
};