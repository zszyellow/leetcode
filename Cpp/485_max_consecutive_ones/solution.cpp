class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tmp = 0, res = 0, len = nums.size();
        for (int i = 0; i < len; i ++)
        {
            if (nums[i] == 1) 
            {
                tmp ++;
                i ++;
                while (nums[i] == 1 && i < len) 
                {
                    tmp ++;
                    i ++;
                }
            }
            if (tmp > res) res = tmp;
            tmp = 0;
        }
        
        return res;
    }
};