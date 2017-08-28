class Solution {
public:
    string longestPalindrome(string s) {
        //mancher algorithm
        if (s.empty() || s.size() == 1) return s;

        // preprocess
        int n = s.length();
        string s2 = "^";
        for (int i = 0; i < n; i++)
            s2 += "#" + s.substr(i, 1);
        s2 += "#$";
        
        // build the array of P
        int m = s2.size();
        int* P = new int[m];
        // id is the center of the palindrome string, and mx is the max border of it
        int id = 0, mx = 0;
        for (int i = 1; i < m - 1; i ++)
        {
            // m_i is the mirror point of i with the center of id
            int m_i = 2 * id - i;
            P[i] = mx > i ? min(mx - i, P[m_i]) : 0;
            
            // extend the P[i]
            while (s2[i+P[i]+1] == s2[i-P[i]-1]) P[i] ++;
            
            // update id and mx
            if (i+P[i] > mx)
            {
                mx = i + P[i];
                id = i;
            }
        }
        
        // find the longest length and center point
        int ml = 0, cnt = 0;
        for (int i = 1; i < m - 1; i ++)
        {
            if (P[i] > ml)
            {
                ml = P[i];
                cnt = i;
            }
        }
        
        return s.substr((cnt - 1 - ml) / 2, ml);    
    }
};