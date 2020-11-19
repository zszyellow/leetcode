class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int mask1 = 0, mask2 = 0;
        for (char &c : word1) mask1 |= (1 << (c - 'a'));
        for (char &c : word2) mask2 |= (1 << (c - 'a'));
        if (mask1 != mask2) return false;
        
        vector<int> cnt1(26), cnt2(26);
        for (char &c : word1) cnt1[c-'a'] ++;
        for (char &c : word2) cnt2[c-'a'] ++;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        
        return cnt1 == cnt2;
    }
};