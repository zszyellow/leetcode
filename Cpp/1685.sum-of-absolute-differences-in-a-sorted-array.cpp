class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), prefix_sum = 0;
        int suffix_sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> res(n);
        for (int i = 0; i < nums.size(); i++) {
            suffix_sum -= nums[i];
            res[i] = (nums[i] * i - prefix_sum) + (suffix_sum - nums[i] * (n-i-1));
            prefix_sum += nums[i];
        }
        return res;
    }
};