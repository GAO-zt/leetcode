class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};

        vector<int> dp(num + 1); // 每个数字的bit为1的位数
        dp[0] = 0;
        dp[1] = 1;
        int num_base = 2;
        for (int i = 2; i < num + 1; ++i) {
            dp[i] = 1 + dp[i - num_base];
            if (i == num_base * 2 - 1) {
                num_base *= 2;
            }
        }
        return dp;
    }
};

/* 规律:
dec bin     cnt
0   0       0
1   1       1

2   10      1 = 1 + cnt[0]
3   11      2 = 1 + cnt[1]

4   100     1 = 1 + cnt[0]
5   101     2 = 1 + cnt[1]
6   110     2 = 1 + cnt[2]
7   111     3 = 1 + cnt[3]

8   1000    1 = 1 + cnt[0]
9   1001    2 = 1 + cnt[1]
10  1010    2 = 1 + cnt[2]
11  1011    3 = 1 + cnt[3]
12  1100    2 = 1 + cnt[4]
13  1101    3 = 1 + cnt[5]
14  1110    3 = 1 + cnt[6]
15  1111    4 = 1 + cnt[7]
*/