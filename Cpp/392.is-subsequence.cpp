class Solution {
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        for (; i < s.size() && j < t.size(); j ++) {
            if (s[i] == t[j]) i ++;
        }

        return i == s.size();
    }
};