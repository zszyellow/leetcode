class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /* Greedy, TC: O(N), SC: O(1) */
        vector<int> cnts(26, 0);
        for (char t : tasks) {
            cnts[t-'A']++;
        }
        sort(cnts.begin(), cnts.end());
        
        int f_max = cnts[25];
        int idle_time = (f_max - 1) * n;
        
        for (int i = 24; i >= 0 && idle_time > 0; -- i) {
            idle_time -= min(f_max-1, cnts[i]);
        }
        idle_time = max(0, idle_time);
        return tasks.size() + idle_time;
    }
};