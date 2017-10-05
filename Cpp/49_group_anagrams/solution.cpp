class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int len = strs.size();
        if (len == 0) return res;
        
        map<string, vector<string>> m;
        vector<string> new_group(1, strs[0]);
        string copy(strs[0]);
        std::sort(copy.begin(), copy.end());
        m[copy] = new_group;
        
        for (int i = 1; i < len; i ++)
        {
            string cp(strs[i]);
            std::sort(cp.begin(), cp.end());
            auto it = m.find(cp);
            if (it != m.end())
                it->second.push_back(strs[i]);
            else
            {
                vector<string> tmp(1, strs[i]);
                m[cp] = tmp;
            }
        }
        
        for (auto p : m) res.push_back(p.second);
        return res;
    }
};