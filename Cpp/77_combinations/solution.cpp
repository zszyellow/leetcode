class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(res, tmp, 1, n, k);
        return res;
    }
    
    void backtrace(vector<vector<int>>& res, vector<int>& tmp, int start, int n, int k)
    {
        if (!k)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i <= n; i ++)
        {
            tmp.push_back(i);
            backtrace(res, tmp, i+1, n, k-1);
            tmp.pop_back();
        }
    }
};