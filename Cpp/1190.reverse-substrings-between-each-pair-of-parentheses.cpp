class Solution {
public:
    string reverseParentheses(string s) {
        /* Using Stack, TC: O(N^2), SC: O(N) */
//         stack<int> st;
//         string res;
        
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '(') {
//                 st.push(i);    
//             } 
//             else if (s[i] == ')') {
//                 int top = st.top();
//                 st.pop();
//                 reverse(s.begin()+top+1, s.begin()+i);
//             }
//         }
        
//         for (char c : s) {
//             if (c != '(' && c != ')') {
//                 res.push_back(c);
//             }
//         }
        
//         return res;
        
        /* Using Stack with no reverse, TC: O(N), SC: O(N) */
        int n = s.size();
        vector<int> pair(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[j] = i;
                pair[i] = j;
            }
        }
        
        string res = "";
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                d = -d;
                i = pair[i];
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};