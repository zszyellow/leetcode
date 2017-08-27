class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        if (s.size() == 0) return result;
        
        int start = 0;
        map<int, int> m;
        for (auto it = s.begin(); it != s.end(); it ++) m[*it] = -1;
        for (int i = 0; i < s.size(); i ++)
        {
            if (m[s[i]] != -1)
            {
                while (start <= m[s[i]]) m[s[start ++]] = -1;
            }
            result = (result > i-start+1) ? result : i-start+1;
            m[s[i]] = i;
        }
        return result;
    }
};