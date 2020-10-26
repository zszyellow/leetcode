class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp{bitset<26>("")};
        int res = 0;
        for (string str: arr) {
            bitset<26> cur;
            for (char c : str) cur.set(c-'a');
            int cur_length = cur.count();
            if (cur_length < str.size()) continue;
            
            for (int i = dp.size()-1; i >= 0; -- i) {
                bitset<26> mask = dp[i];
                if ((cur & mask).any()) continue;
                else {
                    dp.push_back(cur | mask);
                    res = max(res, (int)mask.count() + cur_length);
                }
            }
        }
        return res;
    }
};