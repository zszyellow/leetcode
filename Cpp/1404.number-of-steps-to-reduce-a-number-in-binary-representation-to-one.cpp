class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        bitset<500> cur(s), one(1);
        while (cur != one) {
            res ++;
            if ((cur & one) == 0) cur >>= 1;
            else increment(cur);
        }
        return res;
    }
    
    void increment(bitset<500> &bits) {
        for (auto i = 0; i < bits.size(); ++i) {
            if (bits[i] == 0) {  
                bits[i] = 1;
                break;
            }
            bits[i] = 0;  
        }
    }
};