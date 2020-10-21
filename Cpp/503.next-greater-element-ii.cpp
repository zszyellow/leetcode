class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<pair<int, int>> st;
        
        for (int i = 0; i < nums.size()*2; ++ i) {
            int idx = i >= nums.size() ? i - nums.size() : i;
            while (!st.empty() && st.top().first < nums[idx]) {
                res[st.top().second] = nums[idx];
                st.pop();
            }
            st.push({nums[idx], idx});
        }
        return res;
    }
};