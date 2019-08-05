/*
 * @lc app=leetcode id=1144 lang=cpp
 *
 * [1144] Decrease Elements To Make Array Zigzag
 */
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> res{0, 0};
        int n = nums.size(), left, right;
        
        for (int i = 0; i < n; i ++) {
            left = i > 0 ? nums[i-1] : 1001;
            right = i < n-1 ? nums[i+1] : 1001;
            res[i % 2] += nums[i] < min(left, right) ? 0 : nums[i] - min(left, right) + 1;
        }
        return min(res[0], res[1]);
    }
};