/*
 * @lc app=leetcode id=1134 lang=cpp
 *
 * [1134] Armstrong Number
 */

// @lc code=start
class Solution {
public:
    bool isArmstrong(int N) {
        int t = N, sum = 0, k = to_string(N).length();
                
        while (t) {
            sum += pow(t%10, k);
            t /= 10;
        }
        
        return sum == N;
    }
};
// @lc code=end

