class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for (char c : s) {
            if ('(' == c) cur ++;
            if (')' == c) cur --;
            res = std::max(cur, res);
        }
        return res;
    }
};