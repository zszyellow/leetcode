class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (!st.empty()) {
                char &t = st.top(), &c = s[i];
                if (tolower(t) == tolower(c) &&
                    (isupper(t) && islower(c) || islower(t) && isupper(c))) {
                    st.pop();        
                } else {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }
        
        string res = "";
        while (!st.empty()) {
            res = string(1, st.top()) + res;
            st.pop();
        }
        return res;
    }
};