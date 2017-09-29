class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1, result = 0;
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        while (m >= n)
        {
            long long tmpN = n;
            for (int count = 1; m >= tmpN; count <<= 1, tmpN <<= 1)
            {
                m -= tmpN;
                result += count;
            }
        }
        return result * sign;
    }
};