class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 参考寻找链表中的环
        int fast = 0;
        int slow = 0;
        // 先找会和点，即快慢指针相遇处：
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        // 从起点出发找环的入口，即finder与slow相遇处
        int finder = 0;
        do {
            finder = nums[finder];
            slow = nums[slow];
        } while (finder != slow);        

        return finder;
    }
};