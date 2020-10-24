class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++ mask) {
            vector<int> tmp;
            for (int j = 0; j < n; ++ j) {
                if (mask & (1 << j)) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};