/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        string cur(S);
        dfs(results, cur, 0);
        return results;
    }
    
    void dfs(vector<string>& results, string& cur, int level) {
        if (level == cur.size()) {
            results.push_back(cur);
            return;
        }

        if (isalpha(cur[level])) {
            cur[level] = tolower(cur[level]);
            dfs(results, cur, level+1);
            cur[level] = toupper(cur[level]);
            dfs(results, cur, level+1);
        } else {
            dfs(results, cur, level+1);
        }
    }
};
// @lc code=end

