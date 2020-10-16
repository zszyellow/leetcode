class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        /* brute forece, TC: O(N^2), SC: O(N) */
        // vector<int> res;
        // for (int i = 0; i < prices.size(); i ++) {
        //     int final_price  = prices[i];
        //     for (int j = i + 1; j < prices.size(); j ++) {
        //         if (prices[j] <= prices[i]) {
        //             final_price -= prices[j];
        //             break;
        //         }
        //     }
        //     res.push_back(final_price);
        // }
        // return res;
        
        /* Using stack to maintain the indices of strickly increasing prices
           TC: O(N), SC: O(N) 
        */
        vector<int> res(prices);
        stack<int> st;
        
        for (int i = 0; i < prices.size(); i ++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                res[st.top()] -=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};