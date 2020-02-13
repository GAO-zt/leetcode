class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; //注意边界值
        
        long hi = x / 2; 
        long lo = 1;
        long mid = (hi + lo + 1) / 2; // 因为是求floor，取右边界
        // printf("%d, %d, %d\n", hi, lo, mid);
        while(hi != lo) {
            long mid_2 = mid * mid;
            if (mid_2 == x) {
                return (int)mid;
            } else if (mid_2 > x) {
                hi = mid - 1; // 因为是求floor，取右边界
            } else {
                lo = mid; // 因为是求floor，取右边界
            }
            mid = (hi + lo + 1) / 2; // 因为是求floor，取右边界
            // printf("%d, %d, %d\n", hi, lo, mid);                
        }            
        return (int)mid;
    }
};