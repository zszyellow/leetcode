class Solution {
public:
    string getCommonPrefix(string str1, string str2)
    {   
        int len1 = str1.size(), len2 = str2.size();
        int minLen = len1 < len2 ? len1 : len2;
        string res = "";
        
        for (int i = 0; i < minLen; i ++)
        {
            if (str1[i] != str2[i]) break;
            else res += str1[i];
        }
        
        return res;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        else if (len == 1) return strs[0];
        else 
        {
            string res = getCommonPrefix(strs[0], strs[1]);
            for (int i = 2; i < len; i ++)
                res = getCommonPrefix(res, strs[i]);
            return res;
        }
    }
};