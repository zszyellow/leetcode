class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        
        sort(nums.begin(), nums.end());
        int cur1 = nums[0];
        vector<int> quadruplet(4, 0);

        for (int i = 0; i < nums.size() - 3; i ++)
        {
            if (cur1 == nums[i] && i != 0) continue;
            int cur2 = nums[i+1];
            for (int j = i+1; j < nums.size() - 2; j ++)
            {
                if (cur2 == nums[j] && j != i+1) continue;
                int m = j + 1, n = nums.size() - 1;
                while (m < n)
                {
                    if (nums[m] + nums[n] + nums[i] + nums[j] == target)
                    {
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[m];
                        quadruplet[3] = nums[n];
                        res.push_back(quadruplet);
                        m ++;
                        n --;
                    }
                    else if (nums[m] + nums[n] + nums[i] + nums[j] < target) m ++;
                    else n --;
                }
                cur2 = nums[j];
            }
            cur1 = nums[i];
        }
        
        // avoid repeating
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        
        return res;
    }
};