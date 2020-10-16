class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        /* Sort, TC: O(NlogN), SC: O(N) or O(logN) depending on sort implementation */
        // for (int i = 0; i < A.size(); ++ i) {
        //     A[i] = A[i] * A[i];
        // }
        // std::sort(A.begin(), A.end());
        // return A;
        
        /* Two pointers, TC: O(N), SC: O(N) */
        int l = 0, r = A.size(), cur = A.size() - 1;
        vector<int> res(A);
        while (l < r) {
            int x = A[l] * A[l];
            int y = A[r-1] * A[r-1];
            if (x >= y) {
                res[cur --] = x;
                l ++;
            } else {
                res[cur --] = y;
                r --;
            }
        }
        return res;
    }
};