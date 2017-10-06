class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        vector<int> nums;
        
        for (int i = n*n; i > 0; i --) nums.push_back(i);
        for (int i = 0; i < n; i ++)
        {
            vector<int> temp(n, 0);
            res.push_back(temp);
        }
        
        fill_vector(res, nums, 0, n);
        return res;
    }
    
    void fill_vector(vector<vector<int>> &res, vector<int> &nums, int cur, int n)
    {
        if (cur == n/2)
        {
            if (n % 2 == 1) res[cur][cur] = nums.back();
            return;
        }
        // top
        for (int i = cur; i < n-cur-1; i ++)
        {
            res[cur][i] = nums.back();
            nums.pop_back();
        }
        // right
        for (int i = cur; i < n-cur-1; i ++)
        {
            res[i][n-cur-1] = nums.back();
            nums.pop_back();
        }
        // bottom
        for (int i = n-cur-1; i > cur; i --)
        {
            res[n-cur-1][i] = nums.back();
            nums.pop_back();
        }
        // left
        for (int i = n-cur-1; i > cur; i --)
        {
            res[i][cur] = nums.back();
            nums.pop_back();
        }
        fill_vector(res, nums, cur+1, n);
    }
};