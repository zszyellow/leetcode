class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        int pre = 0, cur = 1, sum = 0;
        for (int i = 0; i < n; i ++)
        {
            sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return sum;
    }
};
