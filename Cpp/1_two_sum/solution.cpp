class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 0) return result;
        
        int tmp;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i ++)
        {
            tmp = target - nums[i];
            if (m.find(tmp) != m.end())
            {
                result.push_back(m[tmp]);
                result.push_back(i);
                break;
            }
            else m[nums[i]] = i;
        }
        return result;
    }
};