class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int res = 0, len = nums.size(), count = 0;
        dfs(nums, S, 0, len, res, count);
        return res;
    }

    void dfs(vector<int>& nums, int S, int idx, int len, int& res, int count)
    {
        if (idx == len)
        {
            if (count == S) res ++;
            return;
        }
        dfs(nums, S, idx+1, len, res, count + nums[idx]);
        dfs(nums, S, idx+1, len, res, count - nums[idx]);
    }
};
