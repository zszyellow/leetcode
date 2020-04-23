/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> bits = {{0, {0}}, {1, {1, 2, 4, 8, 16, 32}}, {2, {3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48}}, {3, {7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56}}, {4, {15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58}},{5, {31, 47, 55, 59}}};
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        for (int i = 0; i <= num && i < 4; i ++) {
            int j = num - i;
            if (j > 5) continue;
            for (int hour : bits[i]) {
                if (hour > 11) continue;
                for (int minutes : bits[j]) {
                    string time = to_string(hour) + (minutes >= 10 ? ":" : ":0") + to_string(minutes);
                    res.push_back(time);
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

