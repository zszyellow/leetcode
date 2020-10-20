class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> counts(1001, 0);
        for (int a : A) counts[a] ++;
        
        for (int i = 1000; i >= 0;  -- i) {
            if (counts[i] == 1) return i;
        }
        return -1;
    }
};