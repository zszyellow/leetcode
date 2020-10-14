class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26, 0);
        for (char& c : s) freq[c-'a'] ++;
        
        string res;
        int count = s.size();
        while (count --) {
            for (int i = 0; i < 26; i ++) {
                if (freq[i]-- > 0) res += 'a' + i; 
            }
            for (int i = 25; i >=0; i --) {
                if (freq[i]-- > 0) res += 'a' + i;
            }
        }
        return res;
    }
};