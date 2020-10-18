class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.size() <= 1) return A;
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) j += 2;
                std::swap(A[i], A[j]);
            }
        }
        return A;
    }
};