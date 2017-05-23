class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, count = 0;
        for (auto n : nums)
        {
            if (count == 0)
            {
                res = n;
                count ++;
            }
            else
            {
                if (res == n) count ++;
                else count --;
            }
        }
        return res;
    }