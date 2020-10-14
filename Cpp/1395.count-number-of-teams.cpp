class Solution {
public:
    int numTeams(vector<int>& rating) {
        /* 1. For every soldier, find how many soilders with larger and smaller rating in the left, get ll and ls
           2. Then, find how many soiders with larger and smaller rating in the rightm get rl and rs
           3. Yield result by accumulate ll*rs + ls*rl
           TC: O(N^2), SC: O(1)
        */
        int res = 0;
        for (int i = 1; i < rating.size()-1; i ++) {
            vector<int> left{0, 0};
            vector<int> right{0, 0};
            for (int j = 0; j < rating.size(); j ++) {
                if (j < i) left[rating[i] < rating[j]] ++;
                else if (j > i) right[rating[i] < rating[j]] ++;
            }
            res += left[0]*right[1] + left[1]*right[0];
        }
        return res;
    }
};