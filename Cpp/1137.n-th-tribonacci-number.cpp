/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) return n == 0 ? 0 : 1;
        
        int tmp, x0 = 0, x1 = 1, x2 = 1;
        for (int i = 3; i < n; i ++) {
            tmp = x0 + x1 + x2;
            x0 = x1;
            x1 = x2;
            x2 = tmp;
        }
        return x0 + x1 + x2;
    }
};
