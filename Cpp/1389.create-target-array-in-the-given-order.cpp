class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) {
            auto it = res.begin();
            res.insert(it+index[i], nums[i]);
        }
        return res;
    }
};