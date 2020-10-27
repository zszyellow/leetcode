class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // max(arr[i]..arr[k]) * max(arr[k+1]..arr[j]) + dp(i, k) + dp(k+1, j)
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> max_val(n, vector<int>(n, 0));
        
        // for (int gap = 0; gap < n; ++gap) {
        //     for (int i = 0; i+gap < n; ++ i) {
        //         if (gap == 0) max_val[i][i+gap] = arr[i];
        //         else if (gap == 1) max_val[i][i+gap] = max(arr[i], arr[i+gap]);
        //         else {
        //             max_val[i][i+gap] = max(max_val[i][i+gap-1], arr[i+gap]);
        //         }
        //     }
        // }
        
        for (int gap = 0; gap < n; ++ gap) {
            for (int i = 0; i+gap < n; ++ i) {
                if (gap == 0) {
                    dp[i][i+gap] = 0;
                    max_val[i][i+gap] = arr[i];
                } else if (gap == 1)  {
                    dp[i][i+gap] = arr[i]*arr[i+gap];
                    max_val[i][i+gap] = max(arr[i], arr[i+gap]);
                }
                else {
                    max_val[i][i+gap] = max(max_val[i][i+gap-1], arr[i+gap]);
                    int tmp = INT_MAX;
                    for (int k = i; k < i+gap; ++k) {
                        tmp = min(tmp, max_val[i][k]*max_val[k+1][i+gap]+dp[i][k]+dp[k+1][i+gap]);
                    }
                    dp[i][i+gap] = tmp;
                }
            }
        }
        
        return dp[0][n-1];
    }
};