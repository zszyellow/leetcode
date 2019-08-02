/*
 * @lc app=leetcode id=1060 lang=cpp
 *
 * [1060] Missing Element in Sorted Array
 */
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        // when wanted element is outbound the vector
        if (k > missing(n-1, nums)) return nums[n-1] + k - missing(n-1, nums);
        
        int l = 0, r = n - 1;
        while (l != r) {
            int mid = l + (r - l) / 2;
            if (missing(mid, nums) < k) l = mid + 1;
            else r = mid;
        }
        
        return nums[l-1] + k - missing(l-1, nums);
    }
    
    int missing(int idx, vector<int>& nums) {
        return nums[idx] - nums[0] -idx;
    }
};
