class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (n % 2 == 0 && i >= n/2) res[i] = i - n/2 + 1; 
            else res[i] = i - n / 2;
        }
        return res;
    }
};