class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cur_balance = 0;
        for (char c : s) {
            cur_balance = c == 'L' ? cur_balance + 1 : cur_balance - 1;
            if (cur_balance == 0) res ++;
        }
        return res;
    }
};