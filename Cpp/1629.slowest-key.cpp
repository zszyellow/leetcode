class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = 'a';
        int start = 0, dur = 0, max_dur = 0, n = releaseTimes.size();
        for (int i = 0; i < n; ++ i) {
            dur = releaseTimes[i] - start;
            if (dur >= max_dur) {
                res = dur == max_dur ? max(res, keysPressed[i]) : keysPressed[i];
                max_dur = dur;
            }
            start = releaseTimes[i];
        }
        return res;
    }
};