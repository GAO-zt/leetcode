class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max_idx = 0;
        for(int i=1;i<A.size();i++) {
            if(A[i] < A[i-1]) {
                return i-1;
            }
        }
        return A.size()-1;
    }
}; 