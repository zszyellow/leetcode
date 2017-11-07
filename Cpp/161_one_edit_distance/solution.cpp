class Solution 
{
public:
    bool isOneEditDistance(string s, string t) 
    {
        int len1 = s.size();
        int len2 = t.size();
        if (abs(len1-len2) > 1) return false;
        
        // case 1
        if (len1 == len2) 
        {
            int mms = 0;
            for (int i = 0; i < s.size(); ++ i)
            {
                if (s[i] != t[i]) ++ mms;
            }
            return mms == 1;
        }
        // case 2 & case 3
        else if (len2 < len1) return isOneEditDistance(t, s);
        else
        {
            bool notm = false;
            for (int i = 0; i < s.size(); ++ i)
            {
                if (s[i] != t[i]) 
                {
                    s.insert(i, 1, t[i]);
                    notm = true;
                    break;
                }
            }
            return !notm || (notm && s == t);
        }
    }
};