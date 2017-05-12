class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || r == 0 || c == 0) return nums;
        int row = nums.size(), col = nums[0].size();
        if (r*c != col*row) return nums;
        
        vector<vector<int>> res(r);
        bool isLegal = true;
        int curR = 0, curC = 0;
        for (int i = 0; i < row; i ++)
        {
            for (int j = 0; j < col; j ++)
            {
                res[curR].push_back(nums[i][j]);
                curC ++;
                if (curC == c) 
                {
                    curC = 0;
                    curR ++;
                }
            }
        }
        return res;
    }
};