class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0, mask = 0;
        
        for (char &c : allowed) 
            mask |= (1 << (c - 'a'));
        
        for (string &word: words) {
            int cur_bits = 0;
            for (char &c : word)
                cur_bits |= (1 << (c - 'a'));
            if ((cur_bits | mask) == mask)
                res ++;
        }
        
        return res;
    }
};