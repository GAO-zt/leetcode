class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        string curr_common = "";
        int str_index = 0;
        int char_index = 0;
        if(strs.empty()) {
            return common;
        }
        else if(strs.size() == 1) {
            return strs[0];
        }        
        while (1) {
            if(char_index < strs[0].size()) {
                curr_common = strs[0][char_index];
            }
            else {
                return (common);
            }
            
            for(str_index = 1; str_index < strs.size(); str_index++) {
                if (char_index >= strs[str_index].size() || strs[str_index][char_index] != curr_common[0]) {
                    return(common);
                }
            }
            common += curr_common;
            char_index++;
        }
        return(common);
    }
};