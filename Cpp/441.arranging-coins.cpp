/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */
class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1 + 8 * (long)n)) / 2);
    }
};


