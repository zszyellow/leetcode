class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return false;
        auto findResult = find(nums.begin(), nums.end(), 0);
        if (k == 0)
        {
            if (findResult == nums.end()) return false;
            else
            {
                findResult ++;
                 if (findResult != nums.end() && *findResult == 0) return true;
                 else return false;
            }
        }
        int len = nums.size();
        for (int start = 0; start < len; start ++)
        {
            bool res = check(nums, start, k, len);
            if (res) return true;
        }
        return false;
    }

    bool check(vector<int>& nums, int start, int k, int len)
    {
        int sum = nums[start];
        for (int i = start+1; i < len; i ++)
        {
            sum += nums[i];
            if (sum % k == 0) return true;
        }
        return false;
    }
};
