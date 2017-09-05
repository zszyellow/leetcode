class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
		int len = s.size();
		bool *match = new bool[len];
 
		for (int i = 0; i < len; i ++){
			match[i] = false;
			if (s[i] == ')' && !st.empty())
            {
				match[st.top()] = true;
                match[i] = true;
				st.pop();				
			}
			else if (s[i] == '(') st.push(i);
		}
 
		int tmp = 0, ans = 0;
		for (int i = 0; i < len; i ++)
        {
			if (!match[i])	{ tmp = 0; continue; }
			tmp ++;
			ans = ans < tmp ? tmp : ans;		
		}
 
		delete[] match;
		return ans;
    }
};