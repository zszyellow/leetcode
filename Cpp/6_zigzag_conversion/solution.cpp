class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.size(), tmp = 0;
        string res;
        for (int i = 0; i < numRows; i ++)
        {
            tmp = i;
            if (i == 0)
            {
                while (tmp < len)
                {
                    res += s[tmp];
                    tmp += 2 * (numRows - i - 1);
                }
            }
            else if (i == numRows - 1)
            {
                while (tmp < len)
                {
                    res += s[tmp];
                    tmp += 2 * i;
                }
            }
            else
            {
                while (tmp < len)
                {
                    res += s[tmp];
                    tmp += 2 * (numRows - i - 1);
                    if (tmp < len)
                        res += s[tmp];
                    tmp += 2 * i;
                }
            }
        }
        return res;
    }
};
