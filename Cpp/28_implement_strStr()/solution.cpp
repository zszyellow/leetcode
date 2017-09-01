class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if (len1 < len2) return -1;
        
        for (int i = 0; i <= len1-len2; i ++)
            if (haystack.substr(i, len2) == needle) return i;
        return -1;    
    }
};