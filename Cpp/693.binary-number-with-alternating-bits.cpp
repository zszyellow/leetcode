class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur_bit = 0, last_bit = -1;
        while (n) { 
            cur_bit = n & 1; 
            if (last_bit == cur_bit) return false;
            last_bit = cur_bit; 
            n >>= 1; 
        }
        return true;
    }
};