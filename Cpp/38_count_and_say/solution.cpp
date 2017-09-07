class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  
        string str = countAndSay(n-1) + ' ', res = "";   
        int count = 1;  
        for (int i = 0; i < str.size() - 1; i ++)
        {  
            if(str[i] == str[i+1]) count ++;
            else
            {  
                res = res + (char)(count + '0') + str[i];
                count = 1;  
            }  
        }  
        return res;  
    }
};