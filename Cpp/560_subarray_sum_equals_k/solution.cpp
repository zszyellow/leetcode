class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> mymap;
        mymap[0] = 1;
        
        for (int i : nums)
        {
            sum += i;
            if (mymap.find(sum-k) != mymap.end()) res += mymap[sum-k];
            mymap[sum] ++;
        }
        
        return res;
    }
};