class Solution {
public:
    bool check(string s)
    {
        int nl = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            if (s[i] == '(') nl ++;
            else if (s[i] == ')' && nl == 0) return false;
            else nl --;
        }
        return nl == 0;
    }
    
    void generate(vector<string>& res, string tmp, int nl, int nr)
    {
        if (nl == 0 && nr == 0)
        {
            if (check(tmp)) res.push_back(tmp);
            return;
        }
        else if (nl == 0) generate(res, tmp+")", 0, nr-1);
        else if (nr == 0) return;
        else 
        {
            generate(res, tmp+"(", nl-1, nr);
            generate(res, tmp+")", nl, nr-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "(", n-1, n);
        return res;
    }
    
};