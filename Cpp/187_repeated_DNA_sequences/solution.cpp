class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0;
        int i = 0;
        int len = s.size();
        
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < len)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                r.push_back(s.substr(i - 10, 10));
        return r;
    }
};