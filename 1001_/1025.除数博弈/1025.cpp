class Solution {
public:
    bool divisorGame(int N) {
        return !(N % 2); // N是偶数则赢，奇数则输，归纳法
    }
};