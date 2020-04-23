/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 0xFFFFFFFF;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
// @lc code=end

