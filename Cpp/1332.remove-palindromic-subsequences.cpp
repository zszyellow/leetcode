class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        bool existsA = (s.find('a') != string::npos);
        bool existsB = (s.find('b') != string::npos);
        if (existsA && existsB) return isPalindrome(s) ? 1 : 2;
        else return 1;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            else {
                i ++;
                j --;
            }
        }
        return true;
    }
};