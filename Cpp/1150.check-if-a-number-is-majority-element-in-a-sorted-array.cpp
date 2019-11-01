/*
 * @lc app=leetcode id=1150 lang=cpp
 *
 * [1150] Check If a Number Is Majority Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if (nums.size() <= 1) return false;
        return nums[nums.size()/2 - 1] == target;
    }
};
// @lc code=end

