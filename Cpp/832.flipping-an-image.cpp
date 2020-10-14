class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            std::reverse(row.begin(), row.end());
        }
        for (auto& row : A) {
            for (int& px : row) {
                px ^= 1;
            }
        }
        return A;
    }
};