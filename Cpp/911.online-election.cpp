/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */
class TopVotedCandidate {
private:
    map<int, int> m;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> count;
        int cur_lead = -1;

        for (int i = 0; i < times.size(); i ++) m[times[i]] = persons[i];
        for (auto it = m.begin(); it != m.end(); it ++) {
            if (++ count[it->second] >= count[cur_lead]) cur_lead = it->second;
            it->second = cur_lead;
        }
    }
    
    int q(int t) {
        return (-- m.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

