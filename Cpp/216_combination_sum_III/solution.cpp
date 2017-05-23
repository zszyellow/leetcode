class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n < 1 || k > 9 || k < 1) return res;
        int max = 0;
        for (int i = 0; i < k; i ++) max += 9 - i;
        if (n > max) return res;
        
        vector<int> cur;
        backtrace(cur, res, 1, 0, k, n);
        
        return res;
    }
    
    void backtrace(vector<int> &cur, vector<vector<int>> &res, int num, int sum, int k, int n)
    {
        if (sum > n || k < 0) return;
        if (sum == n && k == 0)
        {
            res.push_back(cur);
            return;
        }
        for (int i = num; i <= 9; i ++)
        {
            cur.push_back(i);
            backtrace(cur, res, i+1, sum+i, k-1, n);
            cur.pop_back();
        }
    }
};