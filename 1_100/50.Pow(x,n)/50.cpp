class Solution {
public:
    double myPow(double x, int n) {
        // 快速幂，直接看了题解
        long nl = n;
        if (nl < 0) {
            nl = -nl;
            x = 1 / x;
        }

        double ans = 1;
        double curr_product = x;
        for (long i = nl; i > 0; i = i / 2) {
            if (i % 2 == 1) {
                ans *= curr_product;
            }
            curr_product *= curr_product;
        }

        return ans;
    }
};