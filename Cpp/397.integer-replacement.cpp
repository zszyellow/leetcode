class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;
        int res = 0;
        while (n != 1) {
            if (n & 1) {
                if ((n & 3) == 3 && n > 3) n += 1;
                else n -= 1;
            } else {
                n >>= 1;
            }
            res ++;
        }
        return res;
    }
};