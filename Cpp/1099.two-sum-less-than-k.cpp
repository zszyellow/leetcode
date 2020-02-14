/*
 * @lc app=leetcode id=1099 lang=cpp
 *
 * [1099]  Two Sum Less Than K
 */
class Solution {
public:
    // binary search
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = -1;
        for (int i = 0; i < A.size(); i ++) {
            int l = i+1, r = A.size();
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (A[mid] >= K-A[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            l = l - 1;
            if (l > i && l < A.size()) {
                res = max(res, A[i]+A[l]);
            }
        }
        
        return res;
    }

    // two pointers
    int twoSumLessThanK1(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = -1;
        int l = 0, r = A.size() - 1;
        while (l < r) {
            int sum = A[l] + A[r];
            if (sum < K) {
                res = max(res, sum);
                l ++;
            } else {
                r --;
            }
        }
        return res;
    }
};
