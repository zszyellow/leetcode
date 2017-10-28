class Solution {
public:
    bool isAlphanumeric(char c)
    {
        if (c >= 'a' && c <= 'z' || c >='0' && c <= '9' || c >= 'A' && c <= 'Z') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = 0;
        int right = s.size()-1;
        
        while (right > left)
        {
            while(!isAlphanumeric(s[left]) && left < s.size()) left ++;
            while(!isAlphanumeric(s[right]) && 0 <= right) right --;
            if (s[left] != s[right] && tolower(s[left]) != tolower(s[right])) return false;
            left ++;
            right --;
        }
        return true;
    }
};