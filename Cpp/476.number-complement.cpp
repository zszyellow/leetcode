class Solution {
public:
    int findComplement(int num) {
        uint32_t mask = 0xffffffff;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};