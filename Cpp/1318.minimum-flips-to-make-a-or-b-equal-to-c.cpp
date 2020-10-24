class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0, t1 = a & b, t2 = a | b;
        res += __builtin_popcount(c ^ t2);
        while (t1) {
            if ((t1 & (-t1) & c) == 0) res ++;
            t1 &= (t1 - 1);
        }
        // t2 ^= c; 
        // res += __builtin_popcount(t2);
        // res += __builtin_popcount(t1 & t2);
        return res;
    }
};