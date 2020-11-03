class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        unordered_set<int> to_remove;
        stack<int> st;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) {
                    to_remove.insert(i);
                } 
                else {
                    st.pop();    
                }
            }
        }
        
        while (!st.empty()) {
            to_remove.insert(st.top());
            st.pop();
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (to_remove.count(i) == 0) res += s[i]; 
        }
        return res;
    }
};