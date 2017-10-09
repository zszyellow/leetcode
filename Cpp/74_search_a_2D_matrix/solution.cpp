class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if (!n) return false;
        
        vector<int> tmp;
        for (int i = 0; i < m; i ++)
        {
            tmp.push_back(matrix[i][0]);
            tmp.push_back(matrix[i][n-1]);
        }
        if (target < tmp.front() || target > tmp.back()) return false;

        int l = 0, r = tmp.size()-1;
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            if (tmp[mid] < target) l = mid + 1;
            else if (tmp[mid] > target) r = mid -1;
            else return true;
        }
        if (tmp[l] == target || tmp[r] == target) return true;

        vector<int> sub;
        if (l != r || l == r && tmp[l] < target)
        {
            if (l % 2 == 1) return false;
            sub = matrix[l/2];
        }
        else if (l == r && tmp[l] > target)
        {
            if (l % 2 == 0) return false;
            sub = matrix[(l-1)/2];
        }
        return std::binary_search(sub.begin(), sub.end(), target);
    }
};