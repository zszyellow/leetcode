class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, res = nums.size();
        bool hasFound = false;
        while (left < nums.size() && right < nums.size())
        {
            while (sum < s && right < nums.size())
            {
                sum += nums[right ++];
            }
            while (sum >= s && left <= right)
            {
                hasFound = true;
                res = res < right-left ? res : right-left;
                sum -= nums[left ++];
            }
        }
        res = hasFound ? res : 0;
        return res;
    }
};