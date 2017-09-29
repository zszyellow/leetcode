class Solution {
public:
    int makeNum(vector<int> digits)
    {
        int num = 0;
        for (int i = 0; i < digits.size(); i++)
            num = num * 10 + digits[i];
        return num;
    }
    
    static bool compare(const int& a, const int& b)
    {
        return a > b;
    }
    
    int maximumSwap(int num) {
        if (num <= 10) return num;
        int copy = num;
        vector<int> digits;
        while (copy >= 10)
        {
            digits.push_back(copy%10);
            copy /= 10;
        }
        digits.push_back(copy);
        reverse(digits.begin(), digits.end());
        
        int indexl = 0, indexr = 0;
        for (int i = 0; i < digits.size(); i ++)
        {
            vector<int> tmp(digits.begin()+i, digits.end());
            sort(tmp.begin(), tmp.end(), compare);
            if (tmp[0] > digits[i]) 
            {
                for (int j = digits.size()-1; j > i; j --)
                {
                    if (digits[j] == tmp[0])
                    {
                        indexr = j;
                        indexl = i;
                        break;
                    }
                }
                break;
            }
        }
        
        if (indexl == indexr) return num;
        else
        {
            int tmp = digits[indexl];
            digits[indexl] = digits[indexr];
            digits[indexr] = tmp;
            return makeNum(digits);
        }
    }
};