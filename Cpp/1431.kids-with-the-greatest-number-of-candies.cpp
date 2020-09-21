/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int cur_greatest = *max_element(candies.begin(), candies.end());
        for (int candy : candies) { 
            res.push_back(candy + extraCandies >= cur_greatest);
        }
        return res;
    }
};
// @lc code=end