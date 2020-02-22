/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int num : nums) {
            bitmask ^= num;
        }
        
        int rightmost_diff = bitmask & (-bitmask);
        int x = 0;
        for (int num : nums) {
            if (rightmost_diff & num) {
                x ^= num;
            }
        }
        return vector<int>{x, bitmask^x};
    }
};
// @lc code=end

