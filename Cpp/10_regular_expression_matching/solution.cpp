class Solution {
public:
    bool isMatch(string s, string p) {
        // when p is empty
        if (p.empty()) return s.empty();
        
        // when p has one character Or when p has more than one character with second element which isn't '*'
        else if (p.size() == 1 || p[1] != '*')
        {
            if (s.empty() || s[0] != p[0] && p[0] != '.') return false;
            else return isMatch(s.substr(1), p.substr(1));
        }
        
        // when p has more than two characters with second element which is '*'
        else 
        {
            while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
            {
                if (isMatch(s, p.substr(2))) return true;
                s = s.substr(1);
            }
            return isMatch(s, p.substr(2));
        }
    }
};