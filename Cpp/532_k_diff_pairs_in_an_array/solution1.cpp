class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        vector<pair<int, int>> buf;
        pair<int, int> tmp;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len-1; i ++)
        {
            for (int j = i + 1; j < len; j ++)
            {
                if (abs(nums[i]-nums[j]) == k)
                {
                    tmp = make_pair(nums[i], nums[j]);
                    if (buf.empty() || find(buf.begin(), buf.end(), tmp) == buf.end())
                        buf.push_back(tmp);
                }
            }
        }
        
        return buf.size();
    }
};