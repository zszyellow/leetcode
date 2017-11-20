class Solution 
{
public:
    string convertToTitle(int n) 
    {
        return !n ? "" : convertToTitle((n-1) / 26) + (char)((n-1) % 26 + 'A');
    }
};