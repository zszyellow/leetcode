class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        
        // checking the length of string is zero or not
        if (str.size() == 0) return result;
        
        // removing the leading whitespaces
        auto it = str.begin();
        while (it != str.end() && *it == ' ') it ++;
        if (it == str.end()) return result; 
        
        // checking the initial plus or minus sign
        int sign = 1;
        if (*it == '+')  it ++;
        else if (*it == '-') 
        {
            sign = -1;
            it ++;
        }
        else if (*it < '0' || *it > '9') return result;
        
        // convert the string to integer & make sure the number does not exceed the limit
        while (it != str.end() && *it >= '0' && *it <= '9')
        {
            if (sign == 1) {
                if (result > INT_MAX/10 || result == INT_MAX/10 && *it >= '7')
                {
                    result = INT_MAX;
                    break;
                }
            }
            else 
            {
                if (result > INT_MAX/10 || (result == INT_MAX/10 && *it >= '8'))
                {
                    result = INT_MIN;
                    break;
                } 
            }
            result *= 10;
            result += (*it - '0');
            it ++;
        }
        
        return (result == INT_MIN) ? INT_MIN : result * sign;
    }
};