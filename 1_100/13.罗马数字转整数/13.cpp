class Solution {
public:
    int romanToInt(string s) {
        vector<int> dec;
        int sum = 0;
        for(int i=0;i<s.size();++i){
            switch(s[i]) {
                case 'I': dec.push_back(1); break;
                case 'V': dec.push_back(5); break;
                case 'X': dec.push_back(10); break;
                case 'L': dec.push_back(50); break;
                case 'C': dec.push_back(100); break;
                case 'D': dec.push_back(500); break;
                case 'M': dec.push_back(1000); break;
            }
        }
        for(int i=0;i<dec.size()-1;i++) {
            if(dec[i] < dec[i+1]) {
                sum -= dec[i];
            }
            else {
                sum += dec[i];
            }
        }
        sum = sum + dec[dec.size()-1];
        return(sum);              
    }
};