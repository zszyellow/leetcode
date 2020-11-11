class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) return 0;
        int res = 0, N = s.size(), cur_power = 1;
        char cur_char = s[0];
        for (int i = 1; i < N; ++i) {
            if (s[i] == cur_char) cur_power++;
            else {
                res = max(res, cur_power);
                cur_power = 1;
                cur_char = s[i];
            }
        }
        return max(res, cur_power);
    }
};