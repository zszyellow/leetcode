/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        int l = 0, h = N;
        vector<int> res;

        for (int i = 0; i < N; i ++) {
            if (S[i] == 'I') res.push_back(l ++);
            else res.push_back(h --);
        }
        res.push_back(l);

        return res;
    }
};
// @lc code=end

