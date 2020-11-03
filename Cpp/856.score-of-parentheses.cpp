class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, cur_balance = 0, N = S.size();
        for (int i = 0; i < N; ++i) {
            if (S[i] == '(') {
                cur_balance ++;
            }
            else {
                cur_balance --;
                if (S[i-1] == '(') res += 1 << cur_balance;
            }
        }
        return res;
    }
}