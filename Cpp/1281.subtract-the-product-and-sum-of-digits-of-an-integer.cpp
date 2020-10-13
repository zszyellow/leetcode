class Solution {
public:
    int subtractProductAndSum(int n) {
        int res = 0, sum = 0, product = 1, cur_digit = 0;
        while (n > 0) {
            cur_digit = n % 10;
            sum += cur_digit;
            product *= cur_digit;
            n /= 10;
        }
        return product - sum;
    }
};