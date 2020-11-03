class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, N = pushed.size();
        stack<int> st;
        
        while (i < N && j < N) {
            if (st.empty() || st.top() != popped[j]) {
                st.push(pushed[i]);
                i++;
            }
            else {
                st.pop();
                j++;
            }
        }
        
        while (!st.empty()) {
            if (st.top() != popped[j]) break;
            else {
                st.pop();
                j++;
            }
        }
        
        return j == N;
    }
};