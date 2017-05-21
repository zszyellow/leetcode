class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool res = false;
        unordered_map<int, int> m;
        
        for (auto it = nums.begin(); it != nums.end(); it ++)
        {
            if (m.find(*it) != m.end())
            {
                res = true;
                break;
            }
            else 
            {
                m[*it] = 1;
            }
        }
        
        return res;
    }
};