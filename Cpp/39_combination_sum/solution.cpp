class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        if (candidates.empty() || candidates[0] > target) return res;
        for (int i = 0; i*candidates[0] <= target; i ++)
        {
            if (i*candidates[0] == target) 
            {
                vector<int> elm(i, candidates[0]);
                res.push_back(elm);
            } 
            else
            { 
                vector<int> can(candidates.begin()+1, candidates.end());
                auto tmp = combinationSum(can, target - i * candidates[0]);
                vector<int> suffix(i, candidates[0]);
                for (int j = 0; j < tmp.size(); j ++)
                {
                    vector<int> elm(suffix);
                    elm.insert(elm.end(), tmp[j].begin(), tmp[j].end());
                    res.push_back(elm);
                }
            }
        }
        return res;
    }
};