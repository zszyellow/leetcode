class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        unordered_set<bitset<20>> hs;
        int i = 0, start = 0, n = s.size();
        bitset<20> cur, mask(string(k, '1'));
        while (i < k) {
            cur = (cur << 1) | bitset<20>(s[i] - '0');
            i ++;
        }
        hs.insert(cur);
        while (i < n) {
            cur = (cur << 1) & mask | bitset<20>(s[i] - '0');
            hs.insert(cur);
            i ++;
        }
        return hs.size() == (1 << k);
    } 
};