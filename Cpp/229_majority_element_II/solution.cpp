class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size(), num1, num2, count1 = 0, count2 = 0;
        vector<int> res;
        for (int i = 0; i < len; i ++)
        {
            if (num1 == nums[i]) count1 ++;
            else if (num2 == nums[i]) count2 ++;
            else if (count1 == 0) 
            {
                count1 ++;
                num1 = nums[i];
            }
            else if (count2 == 0)
            {
                count2 ++;
                num2 = nums[i];
            }
            else
            {
                count1 --;
                count2 --;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < len; i ++)
        {
            if (num1 == nums[i]) count1 ++;
            if (num2 == nums[i]) count2 ++;
        }
        
        if (count1 > len/3) res.push_back(num1);
        if (count2 > len/3) res.push_back(num2);
        
        return res;
    }
};