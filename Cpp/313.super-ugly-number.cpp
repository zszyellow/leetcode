class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> indices(m), nums;
        nums.push_back(1);
        for (int i = 0; i < n; ++ i) {
            int tmp_min = INT_MAX;
            for (int j = 0; j < m; ++j) {
                tmp_min = min(tmp_min, nums[indices[j]]*primes[j]);
            }
            nums.push_back(tmp_min);
            for (int j = 0; j < m; ++j) {
                if (tmp_min == nums[indices[j]]*primes[j]) indices[j] ++;
            }
        }
        return nums[n-1];
    }
};