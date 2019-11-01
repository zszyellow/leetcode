/*
 * @lc app=leetcode id=1180 lang=cpp
 *
 * [1180] Count Substrings with Only One Distinct Letter
 */

// @lc code=start
class Solution {
public:
    int countLetters(string S) {
        if (S.size() == 0) return 0;
        int res = 0;
        int cur_length = 1;
        char c = S[0];

        for (int i = 1; i < S.size(); i ++) {
            if (S[i] == c) {
                cur_length ++;
            } else {
                res += cur_length * (cur_length + 1) / 2;
                cur_length = 1;
                c = S[i];
            }
        }
        
        return res + cur_length * (cur_length + 1) / 2;
    }
};
// @lc code=end

