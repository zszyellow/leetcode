class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.size() < 2) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        auto left = nums.begin(), right = left + 1;
        while (right != nums.end())
        {
            int tmpL = *left, tmpR = *right;
            if (tmpR - tmpL < k) right ++;
            else if (tmpR - tmpL > k) left ++;
            else 
            {
                res ++;
                while (left != nums.end() && *left == tmpL) left ++;
                while (right != nums.end() && *right == tmpR) right ++;
            }
            if (left == right && right != nums.end()) right ++;
        }
        return res;
    }
};