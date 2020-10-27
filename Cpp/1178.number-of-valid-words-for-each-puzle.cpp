class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int m = words.size(), n = puzzles.size();
        vector<int> puzzle_masks(n, 0);
        unordered_map<int, int> hm;
        for (int i = 0; i < m; ++i) {
            int tmp = 0, cnt = 0;
            for (char &w : words[i]) {
                if (cnt > 7) break;
                else if (tmp & (1 << (w - 'a'))) continue;
                else {
                    tmp |= (1 << (w - 'a'));
                    cnt ++;
                }
            }
            if (cnt <= 7) hm[tmp] ++;
        }
        
        vector<int> res(n , 0);
        for (int i = 0; i < n; ++i) {
            char c = puzzles[i][0];
            // for every subset of puzzles[i][1:]
            for (int mask = 0; mask < (1 << 6); ++ mask) {
                int cur = (1 << (c - 'a'));
                for (int j = 0; j < 6; ++ j) {
                    if (mask & (1 << j)) {
                        cur |= (1 << (puzzles[i][j+1]-'a'));
                    }
                }
                if (hm.find(cur) != hm.end()) res[i] += hm[cur];
            }
        }
        
        return res;
    }
};