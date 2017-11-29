class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        vector<int> caches;
        int res = 0;
        for (int i = 0; i < 32; i ++)
            caches.push_back(pow(2, i));
        for (int val : caches)
            if (n & val) res ++;
        return res;
    }
};