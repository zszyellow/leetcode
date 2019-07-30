/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int max = 0;

        for (int i = A.size()-1; i >= 0; i --) {
            for (int j = B.size()-1; j >= 0; j --) {
                if (A[i] == B[j]) dp[i][j] = dp[i+1][j+1] + 1;
                max = dp[i][j] > max ? dp[i][j] : max;
            }
        }
        return max;
    }
};

