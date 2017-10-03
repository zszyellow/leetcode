class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (std::next_permutation(nums.begin(), nums.end()))
            res.push_back(nums);
               
        return res;
    }
};