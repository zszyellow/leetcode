class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0, right = 1, len = nums.size();
        vector<string> res;
        while (left < len && right < len)
        {
            if (nums[right] - nums[right-1] == 1) right ++;
            else 
            {
                string str = "";
                if (left == right - 1)
                    str += to_string(nums[left]);
                else
                    str += to_string(nums[left]) + "->" + to_string(nums[right-1]);
                res.push_back(str);
                left = right;
                right = left + 1;
            }
        }
        if (left < len)
        {
            string str = "";
            if (left == len - 1) 
            {
                str += to_string(nums[left]);
                res.push_back(str);
            }
            else
            {
                str += to_string(nums[left]) + "->" + to_string(nums[len-1]);
                res.push_back(str);
            }
        }
        
        return res;
    }
};