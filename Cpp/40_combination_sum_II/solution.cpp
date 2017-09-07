class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target || candidates.empty()) return res;
        vector<int> tmp;
        set<vector<int>> s;
        step(s, candidates, target, 0, tmp, 0);
        vector<vector<int>> res2(s.begin(), s.end());
        return res2;
    }
    
    void step(set<vector<int>>& s, vector<int> candidates, int target, int index, vector<int>& tmp, int cur)
    {
        if (index > candidates.size()-1 || cur + candidates[index] > target) return;
        if (cur + candidates[index] == target)
        {
            tmp.push_back(candidates[index]);
            s.insert(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(candidates[index]);
        step(s, candidates, target, index+1, tmp, cur+candidates[index]);
        tmp.pop_back();
        step(s, candidates, target, index+1, tmp, cur);
    }
};