class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        set<vector<int>> set_res;
        vector<int> tmp;
        int len = nums.size();
        for (int i = 0; i <= len; i ++)
            backtrace(set_res, tmp, nums, 0, len, i);
        
        vector<vector<int>> res;
        for (auto val : set_res) res.push_back(val);
        return res;
    }
    
    void backtrace(set<vector<int>>& set_res, vector<int>& tmp, vector<int> nums, int start, int len, int k)
    {
        if (!k)
        {
            set_res.insert(tmp);
            return;
        }
        for (int i = start; i < len; i ++)
        {
            tmp.push_back(nums[i]);
            backtrace(set_res, tmp, nums, i+1, len, k-1);
            tmp.pop_back();
        }
    }
};