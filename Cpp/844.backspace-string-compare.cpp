class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st1, st2;
        for (char &s : S) {
            if (s == '#') {
                if (!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(s);
            }
        }
        
        for (char &t : T) {
            if (t == '#') {
                if (!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(t);
            }
        }
        
        while (!st1.empty() && !st2.empty()) {
            char &a = st1.top(), &b = st2.top();
            if (a != b) return false;
            st1.pop();
            st2.pop();
        }
        
        return st1.size() == st2.size();
    }
};