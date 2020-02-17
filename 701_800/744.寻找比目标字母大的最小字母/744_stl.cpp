class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto pos = std::upper_bound(letters.begin(), letters.end(), target);
        if (pos != letters.end()) {
            // 返回下标
            return letters[pos - letters.begin()];
        } else {
            return letters[0]; // pos == letters.end() 表示 pos == letter.size()
        }
    }
};

// 更简化版本
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto pos = std::upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[pos % letters.size()];
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto pos = ;
        return letters[(std::upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % letters.size()];
    }
};