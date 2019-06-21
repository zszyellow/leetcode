/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Complement of Base 10 Integer
 */
class Solution {
public:
    int bitwiseComplement(int N) {
        int X = 1;
        while (N > X) X = X * 2 + 1;
        return X ^ N;
    }
};

