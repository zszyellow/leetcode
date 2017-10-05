class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int x = 0; x < size / 2; x ++)
        {
            for (int y = x; y < size-x-1; y ++)
            {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[size-1-y][x];
                matrix[size-1-y][x] = matrix[size-1-x][size-1-y];
                matrix[size-1-x][size-1-y] = matrix[y][size-1-x];
                matrix[y][size-1-x] = temp;
            }
        }
    }
};