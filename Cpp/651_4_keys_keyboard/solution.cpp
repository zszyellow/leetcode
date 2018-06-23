class Solution {
public:
    int maxA(int N) {
        int max = N;
        for (int i = 1; i <= N - 3; i++)
            max = std::max(max, maxA(i) * (N - i - 1));
        return max;
    }
};