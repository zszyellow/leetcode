class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hm;
        for (char c : s) {
            hm[c] ++;
        }
        int cnt = 0;
        for (auto &&[key, val] : hm) {
            cnt += val % 2;
        }
        return cnt <= 1;
    }
};