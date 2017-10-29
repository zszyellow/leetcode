class Solution {
public:
    void compressPart(vector<char>& chars, int startIdx, int numForEach, int& i)
    {
        chars.erase(chars.begin()+startIdx+1, chars.begin()+i);
        vector<char> tmp;
        while (numForEach / 10)
        {
            tmp.push_back(numForEach%10 + '0');
            numForEach /= 10;
        }
        tmp.push_back(numForEach + '0');
        std::reverse(tmp.begin(), tmp.end());
        chars.insert(chars.begin()+startIdx+1, tmp.begin(), tmp.end());
        i = startIdx+1+tmp.size();
    }
    
    int compress(vector<char>& chars) 
    {
        if (chars.empty()) return 0;
        char tmp(chars[0]);
        int startIdx(0);
        int numForEach(1);
        int i(1);
        for (; i < chars.size(); i ++)
        {
            if (tmp == chars[i]) numForEach ++;
            else
            {
                if (numForEach != 1) compressPart(chars, startIdx, numForEach, i);
                startIdx = i;
                numForEach = 1;
                tmp = chars[i];
            }
        }
        if (numForEach != 1) compressPart(chars, startIdx, numForEach, i);
        return chars.size();
    }
};