class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool res = false;
        unordered_map<int, vector<int>> m;
        int len = nums.size();
        
        for (int i = 0; i < len; i ++)
        {
            if (res) break;
            if (m.find(nums[i]) != m.end())
            {
                for (auto it = m[nums[i]].begin(); it != m[nums[i]].end(); it ++)
                {
                    if (i - *it <= k) 
                    {
                        res = true;
                        break;
                    }
                }
                if (!res) m[nums[i]].push_back(i);
            }
            else
            {
                vector<int> tmp;
                tmp.push_back(i);
                m[nums[i]] = tmp;
            }
        }
        
        return res;
    }
};