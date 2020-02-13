class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 双指针法
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == s.size()) { // 遍历完表示所有的s都可以找到匹配项
            return true;
        } else {
            return false;
        }
    }
};