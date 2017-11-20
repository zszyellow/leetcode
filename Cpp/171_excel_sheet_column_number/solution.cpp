class Solution 
{
public:
    int titleToNumber(string s) 
    {
        return s == "" ? 0 : titleToNumber(s.substr(0, s.size()-1))*26 + (s.back() - 'A' + 1); 
    }
};