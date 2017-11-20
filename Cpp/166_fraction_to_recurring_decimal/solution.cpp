class Solution 
{
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) 
    {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        
        // if there is no fractional part
        numerator = std::abs(numerator);
        denominator = std::abs(denominator);
        res += std::to_string(numerator / denominator);
        if (numerator % denominator == 0) return res;
        
        // if there is fractional part
        res += '.';
        unordered_map<int, int> hash;
        for (int64_t r = numerator % denominator; r != 0; r %= denominator) 
        {
            if (hash.count(r) > 0) 
            {
                res.insert(hash[r], 1, '(');
                res += ')';
                break;
            }
            hash[r] = res.size();
            r *= 10;
            res += std::to_string(r / denominator);
        }   
        return res;
    }
};