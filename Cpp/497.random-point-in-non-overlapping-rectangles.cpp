/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */
class Solution {
private:
    vector<vector<int>> rects;
    vector<int> psum;
    int total = 0;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;
public:
    
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (auto& rect : rects) {
            total += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            psum.push_back(total);
        }
        uni = uniform_int_distribution<int>{0, total - 1};
    }
    
    vector<int> pick() {
        int target = uni(rng);
        int l = 0, r = rects.size() -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target >= psum[mid]) l = mid + 1;
            else r = mid;
        }
        
        auto& rect = rects[l];
        int width = rect[2] - rect[0] + 1;
        int height = rect[3] - rect[1] + 1;
        int base = psum[l] - width* height;
        return {rect[0] + (target-base) % width, rect[1] + (target-base)/width};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

