class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int cur_max_reach = 0;
        int last_max_reach = 0;
        
        for (int i = 0; i < nums.size()-1; i ++)
        {
            cur_max_reach = std::max(cur_max_reach, i + nums[i]);
            if (i == last_max_reach)
            {
                steps ++;
                last_max_reach = cur_max_reach;
            }
        }
        
        return steps;
    }
};