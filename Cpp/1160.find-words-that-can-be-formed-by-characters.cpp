class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> counts(26, 0);
        for (char c : chars) counts[c-'a'] ++;
        
        for (string &word : words) {
            vector<int> counts_cp(counts);
            bool flag = true;
            for (char c : word) {
                counts_cp[c-'a'] --;
                if (counts_cp[c-'a'] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += word.size();
        }
        return res;
    }
};