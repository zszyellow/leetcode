class Solution {
private:
    // L, R will be in the range [1, 10^6]
    unordered_set<int> prime_nums{2, 3, 5, 7, 11, 13, 17, 19};    
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; ++ i) {
            if (isPrime(setBits(i))) res ++;
        }
        return res;
    }
    
    int setBits(int num) {
        int res = 0;
        while (num) {
            res += (num & 1);
            num >>= 1;
        }
        return res;
    }
    
    bool isPrime(int N) {
        return prime_nums.count(N) == 1;
    }
};