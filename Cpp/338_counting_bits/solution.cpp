class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        int tmp;
        for (int i = 1; i <= num; i ++)
        {
            tmp = res[i >> 1] + (i & 1);
            res.push_back(tmp);
        }
        return res;
    }
};
