class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        int n = word.size();
        for (int mask = 0; mask < (1 << n); ++ mask) {
            int count = 0;
            string tmp = "";
            for (int j = 0; j < n; ++ j) {
                if ((mask & (1 << j)) == 0) {
                    if (count) {
                        tmp += to_string(count);
                        count = 0;
                    }
                    tmp += word[j];
                } else {
                    count ++;
                }
            }
            if (count) tmp += to_string(count);
            res.push_back(tmp);
        }
        return res;
    }
};