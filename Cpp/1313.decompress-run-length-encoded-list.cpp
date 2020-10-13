class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i], val = nums[i+1];
            // while (freq-- > 0) res.push_back(val);
            vector<int> sublist(freq, val);
            res.insert(res.end(), sublist.begin(), sublist.end());
        }
        return res;
    }
};