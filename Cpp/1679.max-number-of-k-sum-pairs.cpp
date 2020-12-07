class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> hm;
        
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i], complement = k - curr;
            if (hm[complement] > 0) {
                res++;
                hm[complement]--;
            } 
            else {
                hm[curr]++;
            }
        }
        
        return res;
    }
};