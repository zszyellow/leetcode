class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size(), res = len;
        vector<int> copy(nums.begin(), nums.end());
        bool flag = true;
        
        sort(copy.begin(), copy.end());
        for (int i = 0; i < len; i ++)
        {
            if (flag && copy[i] == nums[i]) res --;
            if (copy[i] != nums[i]) 
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            for (int i = len - 1; i >= 0; i --)
            {
                if (!flag && copy[i] == nums[i]) res --;
                if (copy[i] != nums[i]) 
                {
                    flag = true;
                    break;
                }
            }   
        }
        
        return res;
    }
};