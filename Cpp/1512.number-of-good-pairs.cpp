/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> hashmap;
        for (int num : nums) {
            res += hashmap[num] ++;
        }
        
        return res;
    }
};
// @lc code=end