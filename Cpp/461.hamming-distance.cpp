/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int tmp = x ^ y;
        
        while (tmp) {
            if (tmp & 1) res ++;
            tmp >>= 1;
        }
        return res;
    }
    
    // Brian Kernighan's Algorithm
    int hammingDistance1(int x, int y) {
        int res = 0;
        int XOR = x ^ y;
        
        while (XOR) {
            XOR &= (XOR - 1);
            res ++;
        }
        return res;
    }
};
// @lc code=end

