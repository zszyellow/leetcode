/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Array 
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i ++) {
            if (grid[i][0] < 0) res += n;
            else {
                int l = 0, r = n;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (grid[i][mid] >= 0) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                if (l < n && grid[i][l] < 0) res += (n-l);    
            }
            
        }
        
        return res;
    }
};
// @lc code=end

