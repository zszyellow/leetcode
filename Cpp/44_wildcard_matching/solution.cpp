class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        // point to string s
        int i = 0;
        // point to string p 
        int j = 0;
        // represent the index of the bullet symbol
        int bullet = -1; 
        // represent the last index of the sequence which the bullet has matched  
        int match;
        
        while (i < m) 
        {
            if (j < n && p[j] == '*') 
            {
                match = i; 
                bullet = j ++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) 
            {
                i ++; 
                j ++;
            }
            else if (bullet >= 0) 
            {
                i = ++ match;
                j = bullet + 1;
            }
            else return false;
        }
        
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};