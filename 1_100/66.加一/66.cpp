
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {};

        vector<int> res(digits.size());

        int carry_in = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int digit_sum = digits[i] + carry_in;
            res[i] = digit_sum % 10;
            carry_in = digit_sum / 10;
        }
        if (carry_in) {
            res.insert(res.begin(), carry_in);
        }
        return res;
    }
};