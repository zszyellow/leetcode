class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0, n = arr1.size(), smallest = 0, cur = 0;
        for (int p : {1, -1}) {
            for (int q : {1, -1}) {
                smallest = p * arr1[0] + q * arr2[0] + 0;
                for (int i = 1; i < n; ++ i) {
                    cur = p * arr1[i] + q * arr2[i] + i;
                    res = max(res, cur - smallest);
                    smallest = min(smallest, cur);
                }
            }
        }
        return res;
    }
};