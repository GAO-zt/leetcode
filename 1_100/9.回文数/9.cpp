class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) {
            return true;
        }
        else if(x < 0 || x % 10 == 0) {
            return false;
        }
        int digit = 0;
        int rev = 0;
        while (x > rev) {
            digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        
        return (x == rev || x == rev / 10);      
    }
};