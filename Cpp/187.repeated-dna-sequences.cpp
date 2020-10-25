class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hm;
        vector<string> res;
        map<char, int> mapping{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int mask = 0, n = s.size(), i = 0;
        
        while (i < 10) {
            mask = (mask << 2) | mapping[s[i]];
            i ++;
        }
        hm[mask] ++;
        while (i < n) {
            mask = (mask << 2) & 0xfffff | mapping[s[i]];
            if (hm[mask] == 1) res.push_back(s.substr(i-9, 10));
            hm[mask] ++;
            i ++;
        }
        return res;
    }
};