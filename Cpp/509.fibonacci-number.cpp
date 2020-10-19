class Solution {
public:
    int fib(int N) {
        /* recursion, TC: O(2^N), SC: O(N) */
        // if (N == 0) return 0;
        // else if (N == 1) return 1;
        // else return fib(N-1) + fib(N-2);
        
        /* Bottom up with memorization, TC: O(N), SC: O(N) */
        // if (N <= 1) return N;
        // auto memorize = [](int N) -> int {
        //     vector<int> cache(N+1, 0);
        //     cache[1] = 1;
        //     for (int i = 2; i <= N; i ++) cache[i] = cache[i-1] + cache[i-2];
        //     return cache[N];
        // };
        // return memorize(N);
        
        /* Iteration, TC: O(N), SC: O(1) */
        // if (N <= 1) return N;
        // int cur = 0, prev1 = 1, prev2 = 0;
        // for (int i = 2; i <= N; ++ i) {
        //     cur = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = cur;
        // }
        // return cur;
        
        /* Math, TC: O(1), SC: O(1)*/
        double goldenRatio = (1 + sqrt(5)) / 2;
        return static_cast<int>(round(pow(goldenRatio, N) / sqrt(5)));
    }
};