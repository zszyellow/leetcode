/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = A[0], max = A[0];
        for (int i = 0; i < A.size(); i ++) {
            min = A[i] < min ? A[i] : min;
            max = A[i] > max ? A[i] : max;
        }
        
        return (max - min - 2 * K) < 0 ? 0 : max - min - 2 * K;
    }
};
// @lc code=end

