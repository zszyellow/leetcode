/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i ++) {
            string t = to_string(i);
            bool flag = true;
            for (int j = 0; j < t.size(); j ++) {
                int d = t[j] - '0';
                if (d == 0 || i % d != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

