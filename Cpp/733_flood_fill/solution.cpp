class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oc = image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, visited, sr, sc, oc, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int r, int c, int oc, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || visited[r][c] || image[r][c] != oc) return;
        image[r][c] = newColor;
        visited[r][c] = true;
        dfs(image, visited, r+1, c, oc, newColor);
        dfs(image, visited, r-1, c, oc, newColor);
        dfs(image, visited, r, c+1, oc, newColor);
        dfs(image, visited, r, c-1, oc, newColor);
    }
};