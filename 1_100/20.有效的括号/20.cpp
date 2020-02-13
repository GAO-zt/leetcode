class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) {
            return true;
        }
        if(s.size() % 2 == 1) {
            return false;
        }        
        
        map<char, char> b_map = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };        
        vector<int> b_vec;
        for (int i=0; i<s.size(); i++) {
            if(b_map.find(s[i]) != b_map.end()) { 
                // 找到左括号
                b_vec.push_back(s[i]);
            }            
            else if(!b_vec.empty() && (b_map[b_vec.back()] == s[i])) { 
                // 栈非空且找到一个对应的右括号
                b_vec.pop_back();
            }
            else {
                return false;
            }
        }
        return (b_vec.empty());
    }
};