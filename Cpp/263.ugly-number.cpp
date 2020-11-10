class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        vector<int> primes{2, 3, 5};
        for (int &prime : primes) {
            while (num % prime == 0) num /= prime;
        }
        return num == 1;
    }
};