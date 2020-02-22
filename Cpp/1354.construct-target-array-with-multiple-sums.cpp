/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long sum = 0;
        for (int num : target) sum += num;
        while (true) {
            int cur_max = pq.top();
            pq.pop();
            sum -= cur_max;
            if (cur_max == 1 || sum == 1) return true;
            if (cur_max < sum || sum == 0 || cur_max % sum == 0) return false;
            cur_max = cur_max % sum;
            sum = sum + cur_max;
            pq.push(cur_max);
        }
        return true;
    }
};
// @lc code=end

