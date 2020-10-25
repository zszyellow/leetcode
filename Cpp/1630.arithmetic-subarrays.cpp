class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res;
        for (int i = 0; i < m; ++ i) {
            res.push_back(isArithmetic(nums, l[i], r[i]));
        }
        return res;
    }
    
    bool isArithmetic(vector<int> &nums, int i, int j) {
        vector<int> cp(nums.begin()+i, nums.begin()+j+1);
        sort(cp.begin(), cp.end()); 
        for (int k = 1; k <= j-i; ++ k) {
            if (cp[k] - cp[k-1] != cp[1] - cp[0]) return false; 
        }
        return true;
    }
};