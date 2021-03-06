/*
 * @lc app=leetcode id=1237 lang=cpp
 *
 * [1237] Find Positive Integer Solution for a Given Equation
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        
        for (int i = 1, j = z; i <= z && j >= 1;) {
            int val = customfunction.f(i, j);
            if (val < z) i++;
            else if (val == z) res.push_back(vector<int>{i ++, j --});
            else j --;
        }
        
        return res;
    }
};