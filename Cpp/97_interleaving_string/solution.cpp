class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<bool>> check(len1+1, vector<bool>(len2+1, false));
        for (int i = 0; i <= len1; i ++)
        {
            for (int j = 0; j <= len2; j ++)
            {
                if (i == 0 && j == 0) check[i][j] = true;
                else if (i == 0)
                    check[i][j] = check[i][j-1] && s2[j-1] == s3[j-1];
                else if (j == 0)
                    check[i][j] = check[i-1][j] && s1[i-1] == s3[i-1];
                else
                    check[i][j] = (check[i-1][j] && s1[i-1] == s3[i-1+j]) || (check[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return check[len1][len2];
    }
};