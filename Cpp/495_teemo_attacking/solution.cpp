class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        int len = timeSeries.size(), res = duration;
        for (int i = 0; i < len - 1 ; i ++)
        {
            if (timeSeries[i] + duration > timeSeries[i+1]) res += (timeSeries[i+1] - timeSeries[i]);
            else res += duration;
        }
        return res;
    }
};