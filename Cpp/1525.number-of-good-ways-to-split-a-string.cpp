class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), cur_state = 0, shift = 0;
        vector<int> dl1(n, 0), dl2(n, 0);

        dl1[0] = 1;
        for (int i = 0; i < n; ++ i) {
            shift = s[i] - 'a';
            if (i > 0) dl1[i] = ((cur_state >> shift) & 1) == 0 ? dl1[i-1] + 1 : dl1[i-1];
            cur_state |= (1 << shift);
        }
        
        cur_state = 0;
        dl2[n-1] = 1;
        for (int j = n - 1; j >= 0; -- j) {
            shift = s[j] - 'a';
            if (j < n - 1) dl2[j] = ((cur_state >> shift) & 1) == 0 ? dl2[j+1] + 1 : dl2[j+1];
            cur_state |= (1 << shift);
        }
        
        int res = 0;
        for (int i = 0; i < n-1; ++ i) {
            res += (dl1[i] == dl2[i+1]);
        }
        return res;
    }
};