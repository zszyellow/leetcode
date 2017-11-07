class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int i    = 0; 
        int j    = 0;
        int num1 = 0;
        int num2 = 0;
        int len1 = version1.size(); 
        int len2 = version2.size();
        
        while (i < len1 || j < len2)
        {
            while (i < len1 && version1[i] != '.')
            {
                num1 = num1*10 + (version1[i]-'0');
                i ++;
            }
            while (j < len2 && version2[j] != '.')
            {
                num2 = num2*10 + (version2[j]-'0');;
                j ++;
            }
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            else
            {
                num1 = 0;
                num2 = 0;
                i ++;
                j ++;   
            }
        }

        return 0;    
    }
};