class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return true;

        long hi = num / 2; 
        long lo = 1;
        long mid = (hi - lo) / 2 + lo; 
        // printf("%d, %d, %d\n", hi, lo, mid);
        while(lo < hi) {
            long mid_2 = mid * mid;
            if (mid_2 == num) {
                return true;
            } else if (mid_2 > num) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            mid = (hi - lo) / 2 + lo;
            // printf("%d, %d, %d\n", hi, lo, mid);                
        }
        if (mid * mid == num) {           
            return true;
        } else {
            return false;
        }
    }
};