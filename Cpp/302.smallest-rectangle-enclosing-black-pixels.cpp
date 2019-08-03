/*
 * @lc app=leetcode id=302 lang=cpp
 *
 * [302] Smallest Rectangle Enclosing Black Pixels
 */
class Solution {
public:
    // TODO: add binary search solution
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = y, right = y;
        int top = x, bottom = x;

        for (int i = 0; i < image.size(); i ++) {
            for (int j = 0; j < image[0].size(); j ++) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j + 1);
                    top = min(top, i);
                    bottom = max(bottom, i + 1);
                }
            }
        }
        return (right - left) * (bottom - top);
    }
};

