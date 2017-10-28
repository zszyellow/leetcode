class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> minLen(triangle.back());
        for (int layer = n-2; layer >= 0; layer --)
        {
            for (int i = 0; i <= layer; i ++)
            {
                minLen[i] = std::min(minLen[i], minLen[i+1]) + triangle[layer][i];
            }
        }
        return minLen[0];
    }
};