/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    // solution 1: next array
    // vector<int> dailyTemperatures(vector<int>& T) {
    //     vector<int> res(T.size(), 0);
    //     vector<int> next(101, INT_MAX);
        
    //     for (int i = T.size()-1; i >= 0; -- i) {
    //         int warmer_index = INT_MAX;
    //         for (int t = T[i] + 1; t <= 100; ++ t) {
    //             warmer_index = next[t] < warmer_index ? next[t] : warmer_index;
    //             // if (next[t] < warmer_index) warmer_index = next[t];
    //         }
            
    //         if (warmer_index < INT_MAX) res[i] = warmer_index - i;
    //         next[T[i]] = i;
    //     }
        
    //     return res;
    // }

    // solution 2: stack
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> st;
        
        for (int i = T.size()-1; i >=0; -- i) {
            while(!st.empty() && T[i] >= T[st.top()]) st.pop();
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        
        return res;
    }
};
// @lc code=end

