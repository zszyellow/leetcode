/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
         if (n == 0) return false;
        long x = (long)n;
        return (x & (-x)) == x;
    }

    bool isPowerOfTwo1(int n) {
        if (n == 0) return false;
        long x = (long)n;
        return (x & (x-1)) == 0;
    }
};
// @lc code=end

