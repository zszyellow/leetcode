class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int res = 0, N = calories.size();
        int cur_sum = accumulate(calories.begin(), calories.begin() + k, 0);
        res += cur_sum > upper ? 1 : (cur_sum < lower ? -1 : 0);
        for (int i = k; i < N; ++i) {
            cur_sum = cur_sum - calories[i - k] + calories[i];
            res += cur_sum > upper ? 1 : (cur_sum < lower ? -1 : 0);
        }
        return res;
    }
};