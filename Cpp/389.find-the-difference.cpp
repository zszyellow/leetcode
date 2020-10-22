class Solution {
public:
    char findTheDifference(string s, string t) {
        int idx = 0;
        for (char c : s) idx ^= (c - 'a');
        for (char c : t) idx ^= (c - 'a');
        return 'a' + idx;
    }
};