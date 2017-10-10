class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int len = nums.size();
        for (int i = 0; i <= len; i ++)
            backtrace(res, tmp, nums, 0, len, i);
        return res;
    }
    
    void backtrace(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int start, int len, int k)
    {
        if (!k)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < len; i ++)
        {
            tmp.push_back(nums[i]);
            backtrace(res, tmp, nums, i+1, len, k-1);
            tmp.pop_back();
        }
    }
};