// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        int mid = (hi - lo) / 2 + lo;
        while (lo < hi) {
            if(isBadVersion(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            mid = (hi - lo) / 2 + lo;
        }
        // 返回的不是mid而是mid左边的值
        return lo;

    }
};