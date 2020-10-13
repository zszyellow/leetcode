class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0, cur_idx = 0;
        
        map<char, int> mapping;
        for (int i = 0; i < keyboard.size(); i ++) {
            mapping[keyboard[i]] = i;
        }
        
        for (char c : word) {
            res += abs(mapping[c] - cur_idx);
            cur_idx = mapping[c];
        }
        
        return res;
    }
};