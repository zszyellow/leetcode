class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size(), sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;

        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            if (k) sum %= k;
            if (hash.find(sum) != hash.end())
            {
                if (i - hash[sum] > 1) return true;
            }
            else hash[sum] = i;
        }
        return false;
    }
};
