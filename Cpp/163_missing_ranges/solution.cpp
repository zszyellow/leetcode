class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty())
        {
            res_insert(res, lower, upper, true, true);
            return res;
        }
        res_insert(res, lower, nums[0], true, false);
        for (int i = 0; i < nums.size()-1; ++ i) res_insert(res, nums[i], nums[i+1], false, false);
        res_insert(res, nums[nums.size()-1], upper, false, true);
        return res;
    }
    
    void res_insert(vector<string>& res, int l, int h, bool isl, bool isu)
    {
        if (l > h || ((h-l == 1 || h == l) && !isl && !isu)) return;
        else if (isl && isu) 
        {
            if (h == l) res.push_back(std::to_string(l));
            else if (h > l) res.push_back(std::to_string(l)+"->"+std::to_string(h));
        }
        else if (isl)
        {
            if (l == INT_MAX) return;
            if (h == 1 + l) res.push_back(std::to_string(l));
            else if (h > 1 + l) res.push_back(std::to_string(l)+"->"+std::to_string(h-1));
        }
        else if (isu)
        {
            if (l == INT_MAX) return;
            if (h == 1 + l) res.push_back(std::to_string(h));
            else if (h > 1 + l) res.push_back(std::to_string(l+1)+"->"+std::to_string(h));
        }
        else if (h == 2 + l) res.push_back(std::to_string(l+1));
        else
        {
            string tmp = std::to_string(l+1) + "->" + std::to_string(h-1);
            res.push_back(tmp);
        }
    }
};