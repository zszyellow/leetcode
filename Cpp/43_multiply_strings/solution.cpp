class Solution {
public:
    // for reversed number string
    string add(string num1, string num2)
    {
        string res = "";
        int len1 = num1.size();
        int len2 = num2.size();
        int over = 0;
        
        for (int i = 0; i < len1 || i < len2; i ++)
        {
            int digit1 = i < len1 ? num1[i] - '0' : 0;
            int digit2 = i < len2 ? num2[i] - '0' : 0;
            int sum = digit1 + digit2 + over;
            res += ('0' + sum % 10); 
            over = sum / 10;
        }
        if (over) res += ('0' + over);
        return res;
    }
    
    // delete the zeros
    string delete_zero(string nums)
    {
        if (nums.size() <= 1 || nums[0] != '0') return nums;
        if (nums[0] == '0') return delete_zero(nums.substr(1));
    }
    
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string res = "";
        
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (int i = 0; i < len2; i ++)
        {
            string tmp(i, '0');
            int digit2 = num2[i] - '0';
            int over = 0;
            for (int j = 0; j < len1; j ++)
            {
                int digit1 = num1[j] - '0';
                int sum = digit1 * digit2 + over;
                char to_push = '0' + (sum % 10);
                tmp += to_push;
                over = sum / 10;
            }
            if (over) tmp += ('0' + over);
            res = add(res, tmp);
        }
        
        reverse(res.begin(), res.end());
        res = delete_zero(res);        
        return res;
    }
};