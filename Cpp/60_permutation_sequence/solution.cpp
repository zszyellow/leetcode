class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i ++) str += ('0' + i);
        for (int i = 1; i < k; i ++) std::next_permutation(str.begin(), str.end());
        return str;
    }
};