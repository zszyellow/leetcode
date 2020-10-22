class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* bit operation, TC: O(N), SC: O(1) */
//         int res = 0, n = nums.size();
//         for (int i = 0; i <= n; i ++) res ^= i;
//         for (int num : nums) res ^= num;
//         return res;
        
        /* math, TC: O(N), SC: O(N) */
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        return n * (n+1) / 2 - sum;
    }
};