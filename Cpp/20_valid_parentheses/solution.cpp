class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        if (s[0] == ']' || s[0] == '}' || s[0] == ')' || s.size()%2 != 0) return false;
        
        stack<char> st;
        for (int i = 0; i < s.size(); i ++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]); 
            else if (s[i] == ']' && st.top() != '[' ||
                    s[i] == '}' && st.top() != '{' ||
                    s[i] == ')' && st.top() != '(')
                return false;
            else st.pop();
        }
        
        return st.empty(); 
    }
};